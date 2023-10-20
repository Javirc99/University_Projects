#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() {}
    ~InsufficientFundsException() {}
    virtual const char* what() const noexcept{
        return "Insufficient funds exception";
    }


};
#endif // __INSUFFICIENT_FUNDS_EXCEPTION_H__
