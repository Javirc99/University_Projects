#include "MyStr.h"
#include <iostream>
#include <cstring>

// No-args constructor
MyStr::MyStr() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
MyStr::MyStr(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
MyStr::MyStr(const MyStr &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str)+ 1];
        std::strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
MyStr::MyStr( MyStr &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// Destructor
MyStr::~MyStr() {
    delete [] str;
}

// Copy assignment operator
MyStr &MyStr::operator=(const MyStr &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment operator
MyStr &MyStr::operator=( MyStr &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

//Display method
void MyStr::display() const{
    std::cout << str << ": " << get_length() << std::endl;
}

//length getter
int MyStr::get_length() const {return std::strlen(str);}

//string getter
const char *MyStr::get_str() const{return str;}

//Equality
bool operator==(const MyStr &lhs, const MyStr &rhs){
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

//Make lowercase
MyStr operator-(const MyStr &obj){

    char *buff = new char[std::strlen(obj.str+1)];
    std::strcpy(buff, obj.str);
    for(size_t i = 0; i < std::strlen(buff); i++){
        buff[i] = std::tolower(buff[i]);
    }
    MyStr temp{buff};
    delete[] buff;
    return temp;
}

//Concatenation
MyStr operator+(const MyStr &lhs, const MyStr &rhs){

    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);

    MyStr temp{buff};
    delete[] buff;
    return temp;
}
