
#include <functional>
#include <vector>
#include <iostream>
using namespace std;
using Logic = std::function<void (int32_t)>;
using dataContainer = std::vector<int32_t>;

void Adaptor(Logic fn, dataContainer& data){
    for(int32_t val: data){
        fn(val);
    }
}






int main (){

dataContainer data{1,2,3};
auto fn= [](int32_t number){
    std::cout<<number * number *number <<"\n";

};


Adaptor (
    [](int32_t number)  {return number * 100;},
    data
);

Adaptor (
    //logic
    [](int32_t number) {std::cout<<number * 0.1f;},
    data 
);
}