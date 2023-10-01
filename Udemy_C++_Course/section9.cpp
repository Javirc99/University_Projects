#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Program to manage a list of data with user menu
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
                    cout << "[ ";
                    for(auto val: vec){
                        cout << val << " ";
                    }
                    cout << "]" << endl;
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
                vec.push_back(toadd);
                cout << toadd << " added" << endl;
            break;

            case 'M':
            case 'm':
                if (vec.size() > 0){
                    double mean{};
                    for(auto val: vec){
                        mean += val;
                    }
                    mean /= vec.size(); 
                    cout << "Mean: " << mean << endl;
                }
                else{
                    cout << "Unable to calculate the mean - no data" << endl;
                }
            break;
            case 'S':
            case 's':
                if (vec.size() > 0){
                    int inf{1000000};
                    for(auto val: vec){
                        if(val < inf) inf = val;
                    }
                    
                    cout << "Smallest item in the list: " << inf << endl;
                }
                else{
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                }
            break;

            case 'L':
            case 'l':
                if (vec.size() > 0){
                    int max{};
                    for(auto val: vec){
                        if(val > max) max = val;
                    }
                    
                    cout << "Largest item in the list: " << max << endl;
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