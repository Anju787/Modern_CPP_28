#include<iostream>

void demo(int n1){
    // n1 is non const int by values
    //lvalue will be assigned, n1 shall not remain const in demo function  (so can be modified)
}

void demo(int& n1){
    //n1 is non const reference to an integer
    //lvalues can be accepted as a reference (nocopy)
    //n1 can be modified but it will modify original data passed
    //example 1 : int n1 {10}; demo(n1);

}



void demo(const int n1){

    // n1 is non const int by values
    //lvalue will be assigned, n1 shall not remain const in demo function  (so cannot be modified)
}
    
void demo(const int& n1){
    //n1 is a const lvalue referecence to an integer l values nad rvalues are both accepted
    //either way , n1 cannot be modifed inside demo function

}
    


void demo(int&& n1){

    // non const rvalue reference to an integer only rvalues are accpeted
   // rvalues will be assigned to n1.. n1 cannot be modified
    
}

void demo(const int&& n1){
  // non const rvalue reference to an integer only rvalues are accpeted
   // rvalues will be assigned to n1.. n1 cannot be modified

}
void demo(int* n1){
   // n1 is a pointer to an int
   //AN r value or lvalue address must be provided here
   //n1 can change a pointer it is holding . n1 can also modify
    
}

//variant is initialised by first value if nothing is given
//rebase 
//chehckput master
//rbase feature add
//git push



void demo(const int* n1){

    // n1 is a pointer to an const int
}

void demo(int* const n1){
    
// n1 is a constant pointer to an   int
//
    
}

void demo (const int* const n1){

    //n1 is constant pointer to a constant integr
    //n1 cannot be reassigned, data cannot be modifed using n1 either
}