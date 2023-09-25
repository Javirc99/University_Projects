#include <iostream>
#include <climits>

using namespace std;

int main(){

    cout << "the syze of a char is " << sizeof(char) << " bytes" << endl;
    cout << "the syze of a int is " << sizeof(int) << " bytes" << endl;
    cout << "the syze of a float is " << sizeof(float) << " bytes" << endl;
    cout << "the syze of a double is " << sizeof(double) << " bytes" << endl;
    cout << "the syze of a long long int is " << sizeof(long long int) << " bytes" << endl;
    cout << "Max long long size: " << LLONG_MAX << endl;

    return 0;
}