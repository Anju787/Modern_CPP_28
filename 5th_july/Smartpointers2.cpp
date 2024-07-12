#include <iostream>
#include <memory>

/*
elision : not to do something , not perform something, ignore / avoid something
Guranteed copy elision : cpp17
*/

#include <iostream>

class Data{

    private :
    int m_value;


    public :

    Data()= default;

// mcq - copy is deleted so it will give error  in line 46
    Data (const Data&) = delete;  //copy constructor  if dleted error and if enabled correct
    Data(Data&&) = delete;
    Data& operator = (const Data&) = delete;
    Data& operator=(Data&&)= delete;

    ~Data() = default;

    explicit Data (int val) : m_value{val} {}

    //explicit constructor cannot be used for type conversion

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }
    
};

void Magic (std::unique_ptr<Data>&& temp)  {}

int main(){

    
   // int* ptr1  =  (int*)  malloc (4);
   // char* ptr2 = (char*) malloc(1);

 // resource : 4 bytes mamory on the heap used by the data object with value 100
   std::unique_ptr<Data> ptr4{new Data{100}};

  Magic(std::move(ptr4));

  ptr4.reset(new Data{99});

/*
If programs requires copying/replicating things don't use unique pointers.
no call by value
no return by value.
*/


}

/*

 Three types of classes are made :  Smart pointers
 1) Weak pointer
 2)Unique pointer  -  which cannot share memory with other
 Shared pointer - one resource can be shared with other
 3)

 dont make l value raw pointers



WEEK 3

CONCURRENCY
 std::thread 
 - joinable , mutex,   lock_guard, unique_lock

 - std::Async_threads

 cpp17

 - std::variant 
 -std::optional
 -guranted copy elision
 -structured binding

 
*/



