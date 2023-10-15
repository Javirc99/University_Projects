#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

// Withdrawal:
//      Included a fee of $1.50 per withdrawal transaction
//
bool Checking_Account::withdrawal(double amount) {
    amount+=def_withdrawal_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << "1.50$]";
    return os;
}

