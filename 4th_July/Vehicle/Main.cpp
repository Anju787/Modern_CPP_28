#include "Operations.h"

int main(){
    //step 1: Make objects

    Operations::CreateCarsAndBikes();

    //step 2: Execute Parallel Functions

    Operations::MapThread();
    Operations::JoinThread();

    //step 3: Serial Functions

    static std::optional<unsigned int> result1=Operations::FindSeatCountById("12");
    
    if(result1.has_value()){
        std::cout<<"seat count for id is:"<<result1.value();

    }

    static std::optional<VrType> result2=Operations::ReturnMatchingInstance("13");
    if(result2.has_value()){
        std::cout<<"Matching instance found:"<<"\n";
        std::visit( [](auto&& val){std::cout<<*val<<"\n";},
        result2.value());
    }
    Operations::Deallocate();



    


}