#include <iostream>
#include <functional>

int main(){


    auto fn = [] (int32_t number, int32_t factor)
    {
        return number * factor;
    };

    //while binding lambda function, don't use & symbol for functional
    auto partially_implemented_fn = std::bind(fn, 100, std::placeholders::_1);

    partially_implemented_fn(20) ;  //FN (100,20)

    partially_implemented_fn(10,20,20,29);
}