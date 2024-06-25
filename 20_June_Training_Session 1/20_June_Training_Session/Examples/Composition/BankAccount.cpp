#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(long number, std::string name, float balance, BankAccountType type, DebitCard *attached)

    :m_accountNumber{number},
    m_accountHolderName{name},
    m_accountBalance{balance},
    m_accountType{type},
    m_attached_card{attached}{}


/*
    memory is allocated to the constructor at the entry point of the constructor
*/



BankAccount::~BankAccount(){
    delete m_attached_card;
    std::cout<<"Bank Account::"<<m_accountNumber<<"is deleted\n";
}

std::ostream &operator<<(std::ostream &os, const BankAccount &rhs)
 {
        os << "m_accountNumber: " << rhs.m_accountNumber
           << " m_accountHolderName: " << rhs.m_accountHolderName
           << " m_accountBalance: " << rhs.m_accountBalance
           << " m_accountType: " << rhs.m_accountType
           << " m_attached_card: " << rhs.m_attached_card;
        return os;
}
