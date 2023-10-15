#include <iostream>
#include "section14Mystr.h"

using namespace std;

//Overloaded operators examples for the Mystring class

int main(){

    Mystring t1 {"Peter"};
    Mystring t2 {"John"};

    cout << boolalpha << endl;

    cout << t1 << " != " << t2 << " --> " << (t1 != t2) << endl;
    cout << t1 << " < " << t2 << " --> " << (t1 < t2) << endl;
    cout << t1 << " > " << t2 << " --> " << (t1 > t2) << endl;

    cout << t1 << " += " << t2;

    t1 += t2;

    cout << " --> " << (t1) << endl;

    

    cout << t1 << " * " << 5 << " --> ";

    Mystring t3 = t1*5;
    cout << (t3) << endl;

    return 0;
}