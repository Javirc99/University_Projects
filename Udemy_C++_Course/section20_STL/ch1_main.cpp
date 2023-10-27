// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Template function to display any type of vector
template <typename T>
void display(const std::deque<T> &deq)
{
    std::cout << "[ ";
    for (const auto &elem : deq)
        std::cout << elem;
    std::cout << "]" << std::endl;
}

bool is_palindrome(const std::string &s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> right_string{};

    for (auto character : s)
    {
        if (isalpha(character))
        {
            right_string.push_back(toupper(character));
        }
    }

    std::deque<char> reversed_string(right_string.rbegin(), right_string.rend());

    return reversed_string == right_string;
}

int main()
{

    std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                          "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result"
              << "String" << std::endl;
    for (const auto &s : test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}