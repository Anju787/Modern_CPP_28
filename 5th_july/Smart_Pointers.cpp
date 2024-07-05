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

int main(){

    int32_t x{10};
    char grade {'A'};
   // int* ptr1  =  (int*)  malloc (4);
   // char* ptr2 = (char*) malloc(1);

   std::unique_ptr<int> ptr1  {(int*) malloc(4)};
   std::unique_ptr<int> ptr1  {new int()};
   std::unique_ptr<char> ptr1  {(char*) malloc(1)};

   //std::unique_ptr<Data> ptr4{new Data{100}};

   Data* d1 {new Data{100}};
   std::unique_ptr<Data>ptr4{d1};

//if(true){
   // std::cout<<*ptr1<<"\n";
//}

//else throw
}


/*

void CalculateResult(input value){
allocate somethingon heap 
ptr =healp memory address

if(value == condition){
do something with ptr}
else {
delete ptr;
throw exception
}
}

 Three types of classes are made :
 1) Weak pointer
 2)Unique pointer  -  which cannot share memory with other
 Shared pointer - one resource can be shared with other
 3)

 dont make l value raw pointers
*/