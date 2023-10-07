#include <iostream>
using namespace std;

// Find maximum of an array using pointers
// int main(){

//     int arr[] = {12, 45, 67, 23, 9};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     int maximum = {-1000000};
//     for(int i{0}; i < size; i++){
//         if(*(arr + i) > maximum) maximum = *(arr+ i);
//     }
    
//     cout << "Maximum value of arr: " << maximum << endl;

//     return 0;
// }

// Reverse an array using pointers
// int main(){

//     int arr[] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     int temp;
//     for(int i{0}; i < size/2; i++){
//         temp = *(arr + i);
//         // cout << "TEMP: " << temp << endl; 
//         // cout << "Valor final antes: " << *(arr + (size-1) - i) << endl;

//         *(arr + i) = *(arr + (size-1) - i);
//         *(arr + (size-1) - i) = temp;


//     }

//     for(int i{0}; i < size; i++){
//         cout << *(arr + i) << " " << endl;
//     }
//     return 0;
// }

#include <string>

int main(){

    string str = "Hello, world!";
    string reversed;
    // Write your code below this line 
    int length = str.length();
    int i = 0;
    for(; i < length; i++){
    
        reversed += str[(length-1) - i];

    }

    for(int j = 0; j < length; j++){
        cout << reversed[j];
    }

    return 0;
}