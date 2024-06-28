/*
std::reference wrapper <T>
this is a wrapper class to hold


*/

#include <iostream>
#include <functional>
#include <vector>

void Magic (int& data){

}

int main(){
    int n1 =10;
    std:: reference_wrapper<int> ref = 1;   //ref is a reference to n1

    //ref is an alterantename  for n1 in main function

    Magic(n1);
    std::reference_wrapper<int> arr[1] {ref};
   std::vector<std::reference_wrapper<int>>v1;
}

//two level hierarchy incase of pointers
// int& data= n1;
// array and vectors of references is not allowed
