#include <iostream>
#include <mutex>
#include <thread>

class MathOperations
{

private :
// std::mutex mt{};
int32_t  m_value{0};
std::mutex mt{};

public:
MathOperations(const MathOperations&) = default;
MathOperations(MathOperations&&) = delete;
MathOperations& operator = (const MathOperations&) = delete;
MathOperations& operator = (MathOperations&&) = delete;
MathOperations()= default;
MathOperations(int val) : m_value {val}  {}
~MathOperations ()= default;

void square(){
   mt.lock();
    std::cout<<"ID : of the thread squre : "<< std::this_thread::get_id()<<"\n";
    std::cout <<"Square of" 
    <<m_value<<"is"
    <<m_value * m_value;
    mt.unlock();
}

int32_t addition (int other) {
    mt.lock();
    std::cout<<"ID : of the thread addition : "<< std::this_thread::get_id()<<"\n";
    mt.unlock();
    return m_value + other;};
//paren paren operator

int64_t operator() () {
     mt.lock();
    std::cout<<"ID : of the thread operator : "<< std::this_thread::get_id()<<"\n";
    mt.unlock();
    return m_value * m_value* m_value;
}

};

//object that behaves like a function (can be invoked like a function called a functor object)

int main(){
        MathOperations m1{100};

    std::thread t1 {&MathOperations::square, &m1 };

     std::thread t2  {std::ref ( m1 )};  
     std::thread t3 {&MathOperations::addition, &m1, 100};

    t1.join();
     
    t2.join();

   t3.join();
    // //thread created by a functor object
     //use the parenthesis operator withnthe object

     //you cannot capture reutn values from a function when executing them  via std::thread

     //note : all parametres passd to std::thread constructor are taken as call by value
     //note:  don't use global everywhere

}

//take first paramteres as object 
//copy parametres
//to avoid copy use reference wrapper -  ref()
//runs the program threads cannot capture return value
// we cannot copy mutex