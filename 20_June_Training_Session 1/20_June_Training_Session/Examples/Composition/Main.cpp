#include "BankAccount.h"
#include "Functionality.h"

int main(){
    std::vector<BankAccount*> accounts;
    CreateObjects(accounts);
    DisplayDebitCardDetails(accounts,8273);
    CountVISACards(accounts);
    Deallocation(accounts);
}

