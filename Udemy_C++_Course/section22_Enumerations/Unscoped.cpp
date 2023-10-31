#include <iostream>
#include <vector>
#include <string>

enum Direction
{
    North,
    South,
    West,
    East
};

std::string direction_to_string(Direction direction)
{
    std::string result;
    switch (direction)
    {
    case North:
        result = "North";
        break;

    case South:
        result = "South";
        break;

    case West:
        result = "West";
        break;

    case East:
        result = "East";
        break;

    default:
        result = "Unknown Direction";
        break;
    }

    return result;
}

void test1()
{
    std::cout << "============ TEST 1 ================" << std::endl;

    Direction direction{North};
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = West;
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = Direction(100);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = static_cast<Direction>(100);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;
}

// Enum for a grocery shopping list
enum Grocery_Item
{
    Milk,
    Bread,
    Apple,
    Orange
};

// Overloading the insertion operator to insert the string representation of the
// provided Grocery_Item parameter into the os
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
    switch (grocery_item)
    {
    case Milk:
        os << "Milk";
        break;
    case Bread:
        os << "Bread";
        break;
    case Apple:
        os << "Apple";
        break;
    case Orange:
        os << "Orange";
        break;
    default:
        os << "Invalid item";
    }
    return os;
}

bool is_valid_grocery_item(Grocery_Item grocery_item)
{
    switch (grocery_item)
    {
    case Milk:
    case Bread:
    case Apple:
    case Orange:
        return true;
        break;

    default:
        return false;
    }
}

void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{

    std::cout << "Grocery List"
              << "\n====================================" << std::endl;
    int invalid_item_count{};
    int valid_item_count{};
    for (Grocery_Item grocery_item : grocery_list)
    {
        std::cout << grocery_item << std::endl;

        // Check if that grocery is valid:
        if (is_valid_grocery_item(grocery_item))
            valid_item_count++;
        else
            invalid_item_count++;
    }

    std::cout << "====================================" << std::endl;
    std::cout << "Valid items: " << valid_item_count << std::endl;
    std::cout << "Invalid items: " << invalid_item_count << std::endl;
    std::cout << "Total items: " << valid_item_count + invalid_item_count << std::endl;
}

void test2()
{
    std::cout << "============ TEST 2 ================" << std::endl;
    std::vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Apple);
    shopping_list.push_back(Apple);
    shopping_list.push_back(Milk);
    shopping_list.push_back(Orange);

    // Careful when casting:
    int Helicopter{1000};
    shopping_list.push_back(Grocery_Item(Helicopter));
    shopping_list.push_back(Grocery_Item(0));

    display_grocery_list(shopping_list);
}

enum State {Engine_Failure, Inclement_Weather, Nominal, Unknown};
enum Sequence {Abort, Hold, Launch};

std::istream &operator>>(std::istream &is, State &state){
    std::underlying_type_t<State> user_input;
    is >> user_input;

    switch (user_input)
    {
    case Engine_Failure:
    case Inclement_Weather:
    case Nominal:
    case Unknown:
        state = State(user_input);
        break;
    
    default:
        std::cout << "User input is not a valid launch state. " << std::endl;
        break;
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, Sequence &sequence)
{
    switch (sequence)
    {
    case Abort:
        os << "Abort";
        break;
    case Hold:
        os << "Hold";
        break;
    case Launch:
        os << "Launch";
        break;
    }

    return os;
}

void initiate(Sequence sequence){
    std::cout << "Initiate " << sequence << " sequence!" << std::endl;
}

void test3()
{
    std::cout << "============ TEST 3 ================" << std::endl;
    State state;
    std::cout << "Launch state: ";
    std::cin >> state;

    switch (state)
    {
    case Engine_Failure:
    case Unknown:
        initiate(Abort);
        break;
    case Inclement_Weather:
        initiate(Hold);
        break;
    case Nominal:
        initiate(Launch);
        break;
    }
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}