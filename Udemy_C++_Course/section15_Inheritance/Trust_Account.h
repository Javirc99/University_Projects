#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"

// Trust Account is a type of Account
//   adds an interest rate
// Withdraw - maximum of 3 withdrawals per year and they can't be higher than 20% of the balance
// Deposit:
//      same as savings account but if deposit are >5000$ they get a 50$ bonus deposited
//

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;  
    static constexpr int max_withdrawals = 3;  
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int num_of_withdrawals;
public:
    Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    bool withdraw(double amount);
    bool deposit(double amount);
};


#endif // _TRUST_ACCOUNT_H_
