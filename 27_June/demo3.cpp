#include <iostream>
#include <functional>

class Data {

    private :

    int m_valueP{0};

    public:

    Data() = default;
    Data(const Data&) = delete;

    Data(Data&&) = delete;
    Data& operator = (Data&& ) = delete;
    Data& operator = (const Data&) =delete;
    ~Data() = default;

    void DisplayReading(int factor){
        std::cout<< m_valueP * factor;
    }

    void static Display(int times){
        std::cout<<"hello"<<times<<"times\n";
    }
};

int main (){
    Data obj{18};    //m_value is 18
  
    obj.DisplayReading(100);   //100 is the factor
    auto fn = std::bind(&Data::DisplayReading, &obj, 100);
    fn();  // obj.displayreading{100};

    Data::Display(10);
    auto binded_static_display = std::bind (Data::Display, 10);
    binded_static_display();

     //data::display(10)

     /*
     For static member functions
     a) object address is mandotory
     b) it must be the first argument after specifying the name of the function in bind
     c)you must use & symbol with the name of the memebr function in bind

     for static member function
     a)no adress involved so no address is required
     b) you should not use & symbol with the name of the function
     */
    
    }