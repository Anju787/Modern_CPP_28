#ifndef DEBITCARD_H
#define DEBITCARD_H
#include <iostream>
#include "DebitCardType.h"

class DebitCard
{
private:
    DebitCardType m_card_type {DebitCardType::VISA};
    short m_card_cvv {0};
    std::string m_card_expiry_date {""};
    long long m_card_number {0};
public:
    DebitCard(DebitCardType type,short cvv,std::string date,long long number);

    DebitCard()=default;
    DebitCard(const DebitCard& other)=delete;
    DebitCard(DebitCard&&)=delete;
    DebitCard& operator=(const DebitCard& other) = delete;
    DebitCard&& operator=(DebitCard&&) = delete;
    ~DebitCard()=default;

    DebitCardType cardType() const { return m_card_type; }

    short cardCvv() const { return m_card_cvv; }

    std::string cardExpiryDate() const { return m_card_expiry_date; }

    long long cardNumber() const { return m_card_number; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
