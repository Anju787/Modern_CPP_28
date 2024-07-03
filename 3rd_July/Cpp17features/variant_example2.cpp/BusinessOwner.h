#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class BusinessOwner{
    

    private:

std::string m_name{""};
float m_net_income{0.0f};

    public:

    BusinessOwner() = default;
    ~BusinessOwner()= default;
    BusinessOwner(const BusinessOwner&) = default;
    BusinessOwner(BusinessOwner&&)= delete;
    BusinessOwner& operator = (const BusinessOwner&) = default;
    BusinessOwner operator = (BusinessOwner&&) = delete;

    Employee(std:: string name , float income)  : m_name{name} , m_net_income{income} {};

    friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs) {
        os << "m_name: " << rhs.m_name
           << " m_net_income: " << rhs.m_net_income;
        return os;
    }

   void CalculateTaxAmount(){std::cout<<0.15f * m_net_income;};

}
;

#endif // EMPLOYEE_H
