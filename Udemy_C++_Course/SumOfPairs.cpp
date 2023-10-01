#include <vector>
#include <iostream>
using namespace std;

int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    int result {0};
    if (vec.size() > 1){
        
        for(int i{0}; i < vec.size(); i++){
            for(int j{i+1}; j < vec.size(); j++){
                
                result += vec[i]*vec[j];
                
            }
            
        }
        
    }
    
     
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}

int main(){

    vector <int> test_vec{2,4,6,8};

    int test = calculate_pairs(test_vec);

    cout << "Result for the vector proposed: " << test << endl; 

    return 0;
}