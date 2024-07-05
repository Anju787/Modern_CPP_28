

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

Data Creator(){

    return Data {100};

}

void Abdorber(Data d1) {
    std::cout<<d1<<"\n";
    return d1;
}

int main(){
    Data obj = Absorber(Data{100});

    std>>cout<<"Object is on main:"<<obj <<"\n";
}