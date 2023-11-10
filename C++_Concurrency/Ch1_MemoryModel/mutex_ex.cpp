#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_val){
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_val);
}

bool list_contains(int value_to_find){
    std::lock_guard<std::mutex> guard(some_mutex);

    return std::find(some_list.begin(), some_list.end(), value_to_find)
        != some_list.end();
}

int main() {
    // Add some values to the list
    add_to_list(42);
    add_to_list(17);
    add_to_list(99);
    
    // Check if values exist in the list
    int value1 = 17;
    int value2 = 100;
    
    if (list_contains(value1)) {
        std::cout << "Value " << value1 << " is in the list." << std::endl;
    } else {
        std::cout << "Value " << value1 << " is not in the list." << std::endl;
    }
    
    if (list_contains(value2)) {
        std::cout << "Value " << value2 << " is in the list." << std::endl;
    } else {
        std::cout << "Value " << value2 << " is not in the list." << std::endl;
    }

    return 0;
}