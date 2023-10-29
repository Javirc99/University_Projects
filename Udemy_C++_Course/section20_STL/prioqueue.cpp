#include <iostream>
#include <queue>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {};
    Person(std::string name, int age) : name(name), age(age) {}

    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
    ~Person() = default;
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(std::priority_queue<T> pq)
{
    T elem;
    std::cout << "[ ";
    while (!pq.empty())
    {
        elem = pq.top();
        std::cout << elem << " ";
        pq.pop();
    }
    std::cout << "]" << std::endl;
}

void display(std::priority_queue<Person> pq)
{
    Person elem;
    std::cout << "[ ";
    while (!pq.empty())
    {
        elem = pq.top();
        std::cout << elem << " ";
        pq.pop();
    }
    std::cout << "]" << std::endl;
}


void test1()
{
    std::priority_queue<int> pq;
    for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
        pq.push(i);

    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;

    display(pq);

    pq.pop();
    display(pq);
}

void test2()
{
    std::priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});
    pq.push(Person{"E", 7});
    pq.push(Person{"F", 27});

    display(pq);
}

int main()
{

    test2();
    return 0;
}