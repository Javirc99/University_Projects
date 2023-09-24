#include <iostream>

using namespace std;

// This program will calculate the area of the room in square meters
int main(){

    double width {0.0},length {0.0};

    cout << "Give me the length of the room in meters: " << endl;
    cin >> length;
    cout << "Give me the width of the room in meters: " << endl;
    cin >> width;

    cout << "The area of the room is " << length * width << " m^2" << endl;

    return 0;
}