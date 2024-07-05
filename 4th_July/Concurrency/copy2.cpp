/*
elision : not to do something , not perform something, ignore / avoid something

Guranteed copy elision : cpp17

*/

#include <iostream>

class Data{

    private :
    int m_value;


    public :

    Data()= default;

// mcq - copy is deleted so it will give error  in line 46
    Data (const Data&) = delete;  //copy constructor  if dleted error and if enabled correct
    Data(Data&&) = delete;
    Data& operator = (const Data&) = delete;
    Data& operator=(Data&&)= delete;

    ~Data() = default;

    explicit Data (int val) : m_value{val} {}

    //explicit constructor cannot be used for type conversion

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }
    
};

Data Magic(){
    return Data{100};
}


int main(){

    //Data d1 {100};
   // Magic(d1);  this will not work  bcoz copy is diabled

   //Magic(99) ; this will also not work bcox conversion is diabled

   Data d1 = Magic();     // an rvalue of type data is used to initiakize an object of type
   //data.  compiler simply reference/modifies the code as DAta d1{100}
}

