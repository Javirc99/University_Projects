#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Implementation of substitution cypher

int main(){

    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    string message {};

    cout << "Enter your message to cypher: ";
    getline(cin, message);

    string encrypted {};
    string decrypted {};

    int counter {};
    for(auto letter: message){
            int index_found = alphabet.find(letter);
            if (letter != ' ')
                encrypted.insert(counter, 1, key[index_found]);
            else
                encrypted.insert(counter, 1, ' ');
            counter++;
    }
    cout << endl << "Encrypting message..." << endl << endl;

    cout << "Cyphered message: " << encrypted << endl;

    counter = 0;
    for(auto letter: encrypted){
            int index_found = key.find(letter);
            if (letter != ' ')
                decrypted.insert(counter, 1, alphabet[index_found]);
            else
                decrypted.insert(counter, 1, ' ');
            counter++;
    }

    cout << endl << "Decrypting message..." << endl << endl;

    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}