#ifndef _MYSTR_H_
#define _MYSTR_H_

class MyStr{
    
        friend bool operator==(const MyStr &lhs, const MyStr &rhs);
        friend MyStr operator-(const MyStr &obj);
        friend MyStr operator+(const MyStr &lhs, const MyStr &rhs);
    private:
        char *str; // pointer to char[] to hold a string
    public:
        //Overloaded constructors
        MyStr();
        MyStr(const char *s);
        MyStr(const MyStr &source);
        MyStr(MyStr &&source);
        //Destructor
        ~MyStr();

        MyStr &operator=(const MyStr &rhs);
        MyStr &operator=(MyStr &&rhs);

        void display() const;

        int get_length() const;
        const char *get_str() const;

};

#endif // _MYSTR_H_