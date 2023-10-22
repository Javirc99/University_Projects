// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

using namespace std;

bool find_substring(const string &word_to_find, const string &target){

    size_t found = target.find(word_to_find);
    if(found == string::npos) return false;
    else return true;
}

int main() {
    
    ifstream file;
    file.open("romeoandjuliet.txt");

    string substring;
    string word;
    int counter = 0;
    int total_words = 0;

    if(file){
        cout << "Enter the substring (case sensitive) to search for: ";
        cin >> substring;

        while(!file.eof()){
            file >> word;

            total_words++;
            if(find_substring(substring, word)) counter++;
        }

    }
    
    cout << total_words << " words were searched"<< endl;
    cout << "The substring " << substring << " was found " << counter << " times" << endl;
    
    return 0;
}

