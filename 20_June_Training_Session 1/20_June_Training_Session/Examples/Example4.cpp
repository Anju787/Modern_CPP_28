#include<iostream>

void Magic1(int n1){
    //accepts both l and r value
}

void Magic2(int& data){
    //accepts only lvalue

}

void Magic3(int&& data){
    //accepts only rvalue
}

void Magic4(const int& data){
    //accepts both r and l value and the number can't be modified
}

void Magic5(const int&& data){
    //accepts only rvalue and the number can't be modified
}

int main(){
    Magic1(10);
    int n=10;
    Magic1(n);
}