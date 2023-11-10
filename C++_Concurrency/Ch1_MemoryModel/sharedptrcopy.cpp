#include <thread>
#include <atomic>
#include <memory>



int main()
{
    std::shared_ptr<int> ptr = std::make_shared<int>(2011);

    for (auto i = 0; i < 10; i++)
    {
        int a{};
        std::thread([ptr]
                    {
    std::shared_ptr<int> localPtr(ptr);
    localPtr = std::make_shared<int>(2014); })
            .detach();
    }
}
