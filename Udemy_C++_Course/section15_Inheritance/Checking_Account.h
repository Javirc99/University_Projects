#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

// Checkings Account is a type of Account
//   has a fee of $1.50 per withdrawal
// Withdraw: includes a fee per withdrawal
// Deposit:
//      same as a regular account
//

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_withdrawal_fee = 1.50;
public:

    Checking_Account(std::string name = def_name, double balance = def_balance);    
    bool withdrawal(double amount);
    // Inherits the Account::deposit methods
};

#endif // _CHECKING_ACCOUNT_H_
