#include <iostream>
using namespace std;

int main(){

    int a{5}, b{10};

    int *ptr1 = &a;
    int *ptr2 = &b;

    cout << "Before swap: *ptr1 -> " << *ptr1 << endl;
    cout << "Before swap: *ptr2 -> " << *ptr2 << endl;

    // Sin la variable temporal al hacer *ptr1 = b, el valor de "a" se vuelve 10 y luego *ptr2 = a, dejaria 10 en *ptr2
    int temp = a;
    *ptr1 = b;
    
    *ptr2 = temp;

    cout << "After swap: *ptr1 -> " << *ptr1 << endl;
    cout << "After swap: *ptr2 -> " << *ptr2 << endl;

    return 0;
}