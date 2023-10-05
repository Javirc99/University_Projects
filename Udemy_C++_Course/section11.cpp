#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Section9 challenge with functions

void print(vector <int> vtr){
    cout << "[ ";
    for (auto number: vtr){
                
            cout << number << " ";
        }
    cout << "]" << endl;
}

void add_number(int number, vector <int> &vec){
    vec.push_back(number);
    cout << number << " added to vector" << endl;
}

void vector_mean(vector <int> vec){
    double mean{0};
    int size{0};
    for (auto number: vec){
        mean += number;
        size++;
    }
    mean /= size;
    cout << "Mean: " << mean << endl;

}

void smallest(vector <int> vec){
    int inf{1000000};
    for(auto val: vec){
        if(val < inf) inf = val;
    }
    
    cout << "Smallest item in the list: " << inf << endl;
}

void largest(vector <int> vec){
    int max{};
    for(auto val: vec){
        if(val > max) max = val;
    }
    
    cout << "Largest item in the list: " << max << endl;
}


int main(){

    char selection {};

    vector <int> vec{};

    do{
        cout << endl << endl << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;

        cout << "Enter your choice: ";
        cin >> selection;
        
        switch(selection){
            case 'P':
            case 'p':
                if (vec.size() > 0){
                    print(vec);
                }
                else{
                    cout << "[] the list is empty" << endl;
                }
            break;

            case 'A':
            case 'a':
                cout << "Enter your desired integer: ";
                int toadd; 
                cin >> toadd;
                add_number(toadd, vec);
            break;

            case 'M':
            case 'm':
                if (vec.size() > 0){
                    vector_mean(vec);
                }
                else{
                    cout << "Unable to calculate the mean - no data" << endl;
                }
            break;
            case 'S':
            case 's':
                if (vec.size() > 0){
                    smallest(vec);
                }
                else{
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                }
            break;

            case 'L':
            case 'l':
                if (vec.size() > 0){
                    largest(vec);
                }
                else{
                    cout << "Unable to determine the largest number - list is empty" << endl;
                }
            break;

            case 'Q':
            case 'q':
                cout << "Goodbye!" << endl;
            break;

            default:
                cout << "Unknown selection, please try again" << endl;
        }

    }while(selection != 'Q' and selection != 'q');


    return 0;
}