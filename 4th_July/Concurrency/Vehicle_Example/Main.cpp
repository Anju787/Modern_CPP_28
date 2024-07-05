#include "Operations.h"

int main(){

    Operations ::CreateCarsAndBikes();
    Operations::MapThreads();
    Operations::JoinThreads();

    std::optional <unsigned int >  result1 = Operations :: FindSeatCountForGivenId("c101") ;

    if (result1.has_value()){
        std::cout<<"seat value for id is :" <<result1.value();
    }

    std::optional <VrType >  result2 = Operations :: ReturnMatchInstance("c101") ;

    if (result1.has_value()){
        std::cout<<"matching instacne found :" <<"\n";

        std::visit ([] (auto&& val){std::cout<<*val<<"\n";}, result2.value());
    }

    Operations::Deallocate();
}

