// Waiting with a mutex

#include <mutex>
#include <thread>
#include <iostream>

std::mutex mut;

void workOnResource(std::string id){
    mut.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << id << std::endl;
    mut.unlock();
}

int main(){
    std::thread t(workOnResource, "thread-1");
    std::thread t2(workOnResource, "thread-2");

    t.join();
    t2.join();
}