# include <iostream>

using namespace std;

// Program to return the change to a certain amount expressed in cents
int main(){

    int mon2eur{}, mon1eur{}, mon50cs{}, mon20cs{}, mon10cs{}, mon5cs{}, mon2cs{}, mon1cs{};

    double euros{};
    int total_cents{};
    cout << "Enter an amount in euros :" << endl;
    cin >> euros;
    // Format the euros into cents:
    total_cents = 100 * euros;
    cout << "Amount entered: " << euros << " €; " << total_cents << "cents" << endl;
    
    mon2eur = total_cents / 200;
    total_cents %= 200;

    mon1eur = total_cents / 100;
    total_cents %= 100;

    mon50cs = total_cents / 50;
    total_cents %= 50;

    mon20cs = total_cents / 20;
    total_cents %= 20;

    mon10cs = total_cents / 10;
    total_cents %= 10;

    mon5cs = total_cents / 5;
    total_cents %= 5;

    mon2cs = total_cents / 2;
    total_cents %= 2;   

    mon1cs = total_cents / 1;
    total_cents %= 1;

    cout << "You can provide change for this amount as follows:" << endl;
    cout << "2 euros :  " << mon2eur << endl;
    cout << "1 euro  :  " << mon1eur << endl;
    cout << "50 cents:  " << mon50cs << endl;
    cout << "20 cents:  " << mon20cs << endl;
    cout << "10 cents:  " << mon10cs << endl;
    cout << "5 cents :  " << mon5cs << endl;
    cout << "2 cents :  " << mon2cs << endl;
    cout << "1 cents :  " << mon1cs << endl;

    return 0;
}