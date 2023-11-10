// A spinlock with std::atomic_flag

#include <atomic>
#include <thread>
#include <iostream>

class Spinlock{
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:

    void lock(){
        while(flag.test_and_set());
    }

    void unlock(){
        flag.clear();
    }
};

Spinlock spin;
int a = 0;

void workOnResource(int arg1, int arg2){
    spin.lock();
    //Shared resource
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "Thread- "<< arg2 << " is incrementing a with " << arg1 << std::endl;
    a += arg1;
    std::cout << "a = " << a << std::endl;
    spin.unlock();
}

int main(){
    std::thread t(workOnResource, 5, 1);
    std::thread t2(workOnResource, 6, 2);

    t.join();
    t2.join();
}