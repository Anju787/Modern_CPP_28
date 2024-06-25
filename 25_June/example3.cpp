#include <iostream>
#include <vector>
#include <functional>


/*
std::function<T>  is a wrapper that can be used to reprsemt a callable of a certain
signature T
SInce this entire datatype is lengthy , we can create an alias
for it wuth using keyword.

[](int32_t number) {return number % 2 ==0;} //lambda
I want to put it in a wrapper

So type T (signature) : bool(int32_t)
so wrapper is : std::function<bool(int32_t)>
Now we create an alias called "predicate"
using predicate = std::function<bool(32_t)>;
*/
using Predicate = std::function<bool (int32_t)>;

/*
for every index "i" in the range of sizze of arr,
call fn by passing rar[1]
*/  

void Adaptor(Predicate fn, int32_t* arr, unsigned int size){
    for(int32_t i =0;i<size;i++){
        //fn(arr[i]);
        if(fn (arr[i]))  {
            std::cout<<arr[i]<<"/n";
        }

    }
}

int main(){

    //lamba are use and throw function

    auto fn= [] (int32_t number) {return number % 2==0;};
    int32_t arr[3] = {11,18,21};
    Adaptor (fn,arr,3);
}

