#include <atomic>
#include <thread>
#include <iostream>
#include <mutex>

std::atomic<int> atom{0};
int someShared{0};

using namespace std::chrono_literals;

void writeShared(){
    someShared = 2011;
    atom.store(2, std::memory_order_release);
}

void readShared(){
    while (!(atom.fetch_sub(1, std::memory_order_acquire) > 0))
    {
        std::this_thread::sleep_for(100ms);
    }

    std::cout << "someShared: " << someShared << std::endl;
    
}

int main(){
    std::cout << std::endl;

    std::thread t1(writeShared);
    std::thread t2(readShared);
    std::thread t3(readShared);

    t1.join();
    t2.join();
    t3.join();
    
    std::cout << "atom: " << atom << std::endl;

    std::cout << std::endl;

}