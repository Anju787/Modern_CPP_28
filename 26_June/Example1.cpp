/*
More aboutlambda function

what  is [] with lambda  - if we wnt to access objects/variables created in the enclosing
function of the lambda , we use []

Some weird things to know about lambda

*/

#include <iostream>
#include <functional>

void Demo(void(*ptr)(int n1, int n2)){
    ptr(10,20);
}

int main(){

    auto fn = [](int n1, int n2)  {std::cout<<n1 + n2;};
    Demo(+fn);

    //allows to use lambda as a function pointer
}


/* int main(){
int data =20;
int value = 100;


lamda object is bound to fn variable in the scope of main function

auto fn =[data, value](int32_t n1, int32_t n2,)  {
    std::cout<<n1 + n2 + data <<"\n";};

fn(10,20); //overload  operator of a class created in  the background
}



capture clause
int n1 = 10

exmple 1 : use of no captured variable
auto fn = [](){std::cout<<"hello";};

example 2 : 
auto fn =[](int n1, int n2) {std::cout<<n1+n2;};
fn(n1,n2);

example 3 -

auto fn =[n1]( int n2) {std::cout<<n1+n2;};
fn(n2);  //only n2 is passed as n1 was already captured.

example 4 
auto fn =[&n1]( int n2) {std::cout<<n1+n2;};
fn(n2);   //only n2 is passed as n1 was already captured.

Example 5 - capture all variable from the surrounding (copies everything into thamambda when they are accessed)

auto fn =[=]( ) {std::cout<<n1+n2+n3;};
fn();   //all varibles were copied by capture into the lambda
whatever captured in [=] is constant . so we cant modify it


OR if we want to capture by reference , we can also modify the value by this
auto fn =[&]( ) {std::cout<<n1+n2+n3;};
fn();    // all variables captured by reference into this lambda
*/