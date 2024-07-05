#ifndef CAR_H
#define CAR_H

#include <iostream>
class Car
{
private:
    /* data */
    std::string m_id{""};
    float m_price{0.0f};
    unsigned int m_seat_count{0};
public:
float InsuranceAmount();
    Car()=delete;
    Car(const Car&)=delete;
    Car(Car&&)=delete;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;
    Car(std::string id,float price,unsigned int count):m_id{id},m_price{price},m_seat_count{count}{}
    


    ~Car()=default;

    std::string id() const { return m_id; }
    void setId(const std::string &id) { m_id = id; }

    float price() const { return m_price; }
    void setPrice(float price) { m_price = price; }

    unsigned int seatCount() const { return m_seat_count; }
    void setSeatCount(unsigned int seat_count) { m_seat_count = seat_count; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price
           << " m_seat_count: " << rhs.m_seat_count;
        return os;
    }

    
};

#endif // CAR_H
