/*
first class functions

A language is said to treat "functions" as first-class if the
following things are possible in the language

a) functions have a properly reconizbale types.
b)functions  can be passed as parameetres to the function 
c) functions can be returned as parameters from the functions(closures)
d) funxtions can be addresssed/copied into other variables   
or function can be saved in to variables
e) functions can be stored in a container

*/

#include <iostream>
#include <functional>
#include <vector>

void Magic(std::function <void(const int32_t)>fn) {
    fn(10);
}

std::function<void(int32_t)>Demo(){
    return [](const int32_t val) {return val * val * val * val;};
}

int main(){


//a function which accepts onn int32 by value, return void
//rule 1
    auto fn =[](const int32_t val)  {std::cout<<val * val;};

    Magic(fn);   //rule 2 works

    //rule 3
    auto ans = Demo();  //accept the function returned in a variable


    //rule 4
    auto temp= ans;  //fn copied
    auto* ptr = &ans;   ///addressing also works



//rule5 : functions can be saved in other container
    std::vector <std::function<void(int32_t)> >fns{fn};

}

