#include <iostream>
#include <vector>
#include "MyStr.h"

using namespace std;

int main(){

    MyStr larry {"Larry"};
    larry.display();    //Larry

    larry = -larry;
    larry.display();    //larry

    cout << boolalpha << endl;

    MyStr moe {"Moe"};
    MyStr stooge = larry;

    cout << (larry == moe) << endl;     //false
    cout << (larry == stooge) << endl;  //true

    MyStr t1 = "Larry" + moe;
    t1.display();
    MyStr t2 = moe+" "+larry;
    t2.display();
    MyStr t3 = moe+" "+larry+ " Curly";
    t3.display();

    return 0;
}