
/*
g(x) is a partial function implemented on f(x,y) where y is 4
 
*/
#include <iostream>
#include <functional>
 
void Formula(int x,int y,int z){
    std::cout<<((x+y)-z);
}
int main(){
    auto partial_formula=std::bind(&Formula,100,std::placeholders::_1,
    std::placeholders::_2);
    partial_formula(10,90);//formula(100 , 10,90)
 
    auto swapped_formula=std::bind(&Formula,std::placeholders::_2,std::placeholders::_3,std::placeholders::_1);
    swapped_formula(10,20,30);
    auto weirdly_mapped_formula=std::bind(&Formula,100,200,std::placeholders::_2);
    weirdly_mapped_formula(99,10); // 99 is discarded because _1 was not used
    }