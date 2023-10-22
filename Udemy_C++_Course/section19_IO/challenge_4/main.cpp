// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    fstream file_read, file_write;
    file_read.open("romeoandjuliet");

    file_write.open("romeoandjuliet_out.txt", std::ios::out);

    string line;

    int line_number {};

    if(file_read && file_write){

        while(!file_read.eof()){
            //Write line number
            file_write << line_number;
            file_write << "\t\t";
            
            //Read line
            getline(file_read, line);

            // Write line in output stream
            file_write << line << endl;;

            line_number++;

        }

    }

    file_read.close();
    file_write.close();
    
    return 0;
}

