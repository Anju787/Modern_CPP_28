#include <iostream>

enum Gear{
    FIRST,
    SECOND
};

enum Rank{
     FIRST,
    SECOND
};

void Magic(int n){
    std::cout<< n* 100;
}

int main(){
    //Problems which will be solved by enum class
    FIRST; // 1. Not mandatory to prefix enum name (compiler confusion) error during runtime
    Gear g1=Gear::FIRST;
    Rank r1=Rank::FIRST;

    if (g1==r1) // 2. Shouldn't compare enum of 2 types but no error is shown on basis of integer
    {
        std::cout<<"Should be invalid"<<"\n";
    }
    
    Magic(r1);// 3. auto conversion of enum to integer without consent

}