#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Define a mutex

// Function to increment a shared variable
void increment(int &counter, int n) {
    // Get the ID of the current thread
    std::thread::id threadId = std::this_thread::get_id();

    for (int i = 0; i < n; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
            counter++;
            
        }

        // Print the thread ID
        
    }
    
}

int main() {
    int sharedCounter = 0;
    int incrementAmount = 1000000;

    // Create two threads
    std::thread thread1(increment, std::ref(sharedCounter), incrementAmount);
    std::thread thread2(increment, std::ref(sharedCounter), incrementAmount);

    // Wait for the threads to finish
    thread1.join();
    thread2.join();

    // Output the final value of the shared counter
    std::cout << "Shared counter: " << sharedCounter << std::endl;

    return 0;
}
