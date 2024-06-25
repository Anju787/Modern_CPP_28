//week 2 - modern cpp starts
/*
software to be built 
--> diagnostics of a car at workshop

Functional programming - passing fucntion as input
Objective - I want to write an "adaptor " function
which will accept:
a) vector of integer 32 bit numbers

b) a function that accepts a single integer 32 value and returns void

Adaptor should "map" function provided onto the data provided

*/

#include <iostream>
#include <vector>

void Square(int32_t number){
    std::cout<<number * number <<"\n";
}

void Cube(int32_t number){
    std::cout<<number * number *number <<"\n";

}


void Adaptor(
    void (*fn) (int32_t number),
    std::vector<int32_t>& data

    ) {
        //for each number in data , run the function with the number
        for(int32_t val : data){
            (*fn), (val);
        }
    }


int main(){
    std::vector<int32_t>data{1,2,3,4,5};
 Adaptor(&Cube, data);
Adaptor(&Square, data);
}

//user can design their own function and use its logic to process data.

/*void (*ptr)(int32_t number) = &Square;

    void (*temp)(int32_t number) = &Cube;
    (*temp)(10);   //calls cube function as cube(10)
    (*ptr)(9); //calls square function as Square(9)
*/