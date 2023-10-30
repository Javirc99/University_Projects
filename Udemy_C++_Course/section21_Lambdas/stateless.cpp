// Stateless lambda expressions
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void print_if(std::vector<int> nums, bool (*predicate)(int)){
    for(int i: nums)
        if(predicate(i))
            std::cout << i;
}

int main()
{
    // const int n{3};
    // int nums[n]{10, 20, 30};

    // auto sum = [](int nums[], int n)
    // {
    //     int sum{0};
    //     for (int i = 0; i < n; i++)
    //     {
    //         sum += nums[i];
    //     }
    //     return sum;
    // };

    //////////////////////////////////////////////////////////////////////////////

    /* USING POINTERS AND REFERENCES WITH LAMBDAS*/
    // std::cout << sum(nums, 3) << std::endl;

    // int test_score1{88};
    // int test_score2{75};

    // auto bonus = [](int &score1, int &score2, int bonus_points){
    //     score1 += bonus_points;
    //     score2 += bonus_points;

    // };

    // bonus(test_score1, test_score2, 5);

    // std::cout << "Test_score1 = " << test_score1 << std::endl;
    // std::cout << "Test_score2 = " << test_score2 << std::endl;

    //////////////////////////////////////////////////////////////////////////////

    // int *test_score1 = new int;
    // int *test_score2 = new int;

    // *test_score1 = 88;
    // *test_score2 = 75;

    // auto bonus = [](int *score1, int *score2, int bonus_points)
    // {
    //     *score1 += bonus_points;
    //     *score2 += bonus_points;
    // };

    // bonus(test_score1, test_score2, 5);

    // std::cout << "Test_score1 = " << *test_score1 << std::endl;
    // std::cout << "Test_score2 = " << *test_score2 << std::endl;

    // std::vector<int> test_scores{93,88,75,68,65};

    // auto bonus = [](std::vector<int> &scores, int bonus_points){
    //     for(int &score: scores){
    //         score += bonus_points;
    //     }
    // };

    // bonus(test_scores, 5);

    // std::cout << "test scores: " << std::endl;
    // std::cout << test_scores[0] << std::endl;
    // std::cout << test_scores[1] << std::endl;
    // std::cout << test_scores[2] << std::endl;
    // std::cout << test_scores[3] << std::endl;
    // std::cout << test_scores[4] << std::endl;

    //////////////////////////////////////////////////////////////////////////////

    // std::vector<int> test_scores1{93, 88, 75, 68, 65};
    // std::vector<float> test_scores2{88.5, 85.5, 75.5, 68.5, 65.5};

    // auto bonus = [](auto &scores, int bonus_points)
    // {
    //     for (auto &score : scores)
    //     {
    //         score += bonus_points;
    //     }
    // };

    // bonus(test_scores1, 5);
    // bonus(test_scores2, 5);

    // std::cout << "test scores1: " << std::endl;
    // std::cout << test_scores1[0] << std::endl;
    // std::cout << test_scores1[1] << std::endl;
    // std::cout << test_scores1[2] << std::endl;
    // std::cout << test_scores1[3] << std::endl;
    // std::cout << test_scores1[4] << std::endl;

    // std::cout << std::endl;

    // std::cout << "test scores2: " << std::endl;
    // std::cout << test_scores2[0] << std::endl;
    // std::cout << test_scores2[1] << std::endl;
    // std::cout << test_scores2[2] << std::endl;
    // std::cout << test_scores2[3] << std::endl;
    // std::cout << test_scores2[4] << std::endl;

    std::vector<int> nums{1,2,3};

    print_if(nums, [] (auto x) {return x % 2 == 0;});  // Displays evens
    std::cout << std::endl;

    print_if(nums, [] (auto x) {return x % 2 != 0;});  // Displays odds
    std::cout << std::endl;

    return 0;
}