#include <iostream>

class Vehicle
{
private:
    std::string m_id{""};
    std::string m_modelName{""};
public:
    Vehicle() = default;
    ~Vehicle() = default;
    /*
        Vehicle constructor that takes one const lvalue reference
        to a Vehicle as a parameter.
    */
    Vehicle(const Vehicle& other) = delete;

    Vehicle(std::string id,std::string name) : m_id{id}, m_modelName{name} {}
};

int main(){
    Vehicle v1{"101","Dzire"};
    // Vehicle v2{v1}; //copy constructor v2[101 | Dzire]
    Vehicle v3=v1;
    /*
    copy constructor : creating the object for the first time
    copy Assigment : object is already constructor
    */
   Vehicle v4{};
   v4=v1;
}