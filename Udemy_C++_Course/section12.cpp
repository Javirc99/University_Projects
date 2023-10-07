#include <iostream>

using namespace std;

void print(const int *arr, int arr_size){

    for(int i{0}; i < arr_size; i++){
        cout << *(arr+i) << " ";
    }
    cout << endl;
}

int *apply_all(int *arr1, int arr1_size, int *arr2, int arr2_size){
    int *result = new int[arr1_size * arr2_size];

    int k {0};
    for(int i{0}; i < arr2_size; i++){
        for(int j{0}; j < arr1_size; j++){
            
                result[k] = arr1[j] * arr2[i];
                k++;
            
        }
    }

    return result;

}

int main(){

    const size_t array1_size {5}, array2_size {3};
    int array1[]{1,2,3,4,5};
    int array2[]{10,20,30};

    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size); 

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: ";
    print(results, results_size);

    cout << endl;   

    return 0;
}