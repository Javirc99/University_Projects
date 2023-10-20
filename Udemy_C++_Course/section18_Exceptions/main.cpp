#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    // test your code here

    try{
        std::unique_ptr<Account> javis_account = 
            std::make_unique<Checking_Account> ("Javi", -100.0);

        std::cout << "Use javis_account" << std::endl;
    }
    catch (const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
    }

    try{
        std::unique_ptr<Account> javis_second_account = 
            std::make_unique<Checking_Account> ("Javier", 1000.0);

        javis_second_account -> withdraw(2000.0);

        std::cout << "Withdrawn from javis_second_account" << std::endl;
    }
    catch(const InsufficientFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

