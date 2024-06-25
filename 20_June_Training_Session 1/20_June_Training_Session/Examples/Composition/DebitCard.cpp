#include "DebitCard.h"

DebitCard::DebitCard(DebitCardType type, short cvv, std::string date, long long number)

    :m_card_cvv {cvv},
    m_card_expiry_date {date},
    m_card_number {number},
    m_card_type {type}{}


// DebitCard::~DebitCard()
// {
//     std::cout<<"Debit card of number:: "<<m_card_number<<"is deleted\n";
// }

std::ostream &operator<<(std::ostream &os, const DebitCard &rhs)
{
        os << "m_card_type: " << int(rhs.m_card_type)
           << " m_card_cvv: " << rhs.m_card_cvv
           << " m_card_expiry_date: " << rhs.m_card_expiry_date
           << " m_card_number: " << rhs.m_card_number;
        return os;
}
