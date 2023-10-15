#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, num_of_withdrawals{0} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) and given a bonus of 50$ if amount > 5000$
//      and then the updated amount will be deposited
//
bool Trust_Account::deposit(double amount) {

    if(amount >= bonus_threshold) 
        amount += bonus_amount;

    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {

    if (amount > balance*max_withdraw_percent || num_of_withdrawals >= max_withdrawals) {
        return false;
    } else{
        num_of_withdrawals++;
        return Savings_Account::withdraw(amount);
    }
        
}


std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, Withdrawals: " << account.num_of_withdrawals << "]";
    return os;
}

