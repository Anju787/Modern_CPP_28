#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "DebitCard.h"
#include "BankAccountType.h"
#include <iostream>

class BankAccount
{
private:
    long m_accountNumber {0};
    std::string m_accountHolderName {""};
    float m_accountBalance {0.0f};
    BankAccountType m_accountType {BankAccountType::CURRENT};
    DebitCard *m_attached_card;
public:
    BankAccount(long number,std::string name,float balance,BankAccountType type,DebitCard* attached);

    BankAccount()=default;
    BankAccount(const BankAccount& other)=delete;
    BankAccount(BankAccount&&)=delete;
    BankAccount& operator=(const BankAccount& other) = delete;
    BankAccount&& operator=(BankAccount&&) = delete;
    ~BankAccount();

    long accountNumber() const { return m_accountNumber; }
    // void setAccountNumber(long accountNumber) { m_accountNumber = accountNumber; }

    std::string accountHolderName() const { return m_accountHolderName; }

    float accountBalance() const { return m_accountBalance; }

    BankAccountType accountType() const { return m_accountType; }

    DebitCard *attachedCard() const { return m_attached_card; }



    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs);

    
    
};

#endif // BANKACCOUNT_H
