#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <chrono>

template<typename Iterator, typename T>
struct accumulate_block {
    void operator()(Iterator first, Iterator last, T& result) {
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    unsigned long const length = std::distance(first, last);

    if (!length)
        return init;

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
    unsigned long const hardware_threads = std::thread::hardware_concurrency();

    unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

    unsigned long const block_size = length / num_threads;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);
    Iterator block_start = first;

    for (unsigned long i = 0; i < (num_threads - 1); ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
        block_start = block_end;
    }
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    for (unsigned long i = 0; i < (num_threads - 1); ++i) {
        threads[i].join();
    }

    return std::accumulate(results.begin(), results.end(), init);
}

int main() {
    // Create a large data vector with 1,000,000,000 elements, all initialized to 1.
    std::vector<int> data(1000000000, 1);
    
    // Measure the time for parallel_accumulate
    auto start_time = std::chrono::high_resolution_clock::now();
    long long int result_parallel = parallel_accumulate(data.begin(), data.end(), 0);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    
    std::cout << "Parallel Accumulate Result: " << result_parallel << std::endl;
    std::cout << "Parallel Accumulate Time: " << elapsed_time.count() << " seconds" << std::endl;
    
    // Measure the time for std::accumulate (single-threaded)
    start_time = std::chrono::high_resolution_clock::now();
    long long int result_single_thread = std::accumulate(data.begin(), data.end(), 0);
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    
    std::cout << "std::accumulate (Single-thread) Result: " << result_single_thread << std::endl;
    std::cout << "std::accumulate (Single-thread) Time: " << elapsed_time.count() << " seconds" << std::endl;
    
    return 0;
}
