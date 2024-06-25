#include <iostream>
#include <vector>


/*
    to avoid duplication of constructor we use constructor delegation
    size_t --> unsigned long

*/
enum class Rating{
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    _NO_STAR,
};

class Car
{
private:
    unsigned int m_id {0};
    float m_price {0.0f};
    Rating m_safetyRating {Rating :: _NO_STAR};
public:
    Car(unsigned int id, float price, Rating rating) //Constructor delegation
    :Car(id,price){
        m_safetyRating=rating;
    }
    Car(unsigned int id, float price):m_id {id}, m_price {price}{};
    Car()=delete;
    Car(const Car&)=default;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;
    Car(Car&&)=delete;
    ~Car()=default;
};


int main(){
    Car c1(101,10000.5f,Rating::_1_STAR);
    int32_t n1=10; //the memory will occupy 32 bits for n1 variable.  
    auto c2{new Car{102,20000.5f,Rating::_3_STAR}};

    // std::vector<Car> car {c1,c2};

    /*
        error for creating the vector
        Solution 1: enable copy constructor    
        Solution 2: move the data will not work in this context
        Solution 3: Create data inside the vector directly (emplacing)
    */


   std::vector<Car> cars;
   cars.emplace_back(101,10000.5f,Rating::_1_STAR);
   cars.emplace_back(102,20000.5f,Rating::_3_STAR);

   std::cout<<"Number of elements ::"<<cars.size();




}

