#include<iostream>
#include <vector>

/*
    FN(XYZ VAL)--.CALL BY VALUE
    FN(XYZ& VAL)--CALL BY REFERENCE
    FN(XYZ&& VAL)--RVALUE REFERENCE
    FN(CONST XYZ& VAL)--LVALUE AND RVALUE BUT THE COMPILER WILL DECIDE
*/


void Deallocate(std::vector<int*>&& values){//rvalue reference
    for(int *v:values){
        delete v;
    }
}


void Magic(std::vector<int*>&& values){
    for(int* v:values){
        std::cout<<*v<<"\n";
    }
    Deallocate(std::move(values));//TRANSFER OWNERSHIP OF HEAP ALLOCATED DATA
}


int main(){
    std::vector<int*> data {new int(10),new int (20)};

    Magic(std::move(data)); //transfer ownership of heap allocated data

    //accessing data variable after move is complete
    //WILL BE UNDEFINED BEHAVIOUR
}