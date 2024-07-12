/*
cpp17 - folding arguments around an operator(fols expression)
*/

#include<iostream>

/*
add is a function template that takes
1or more arguments of unknown type in each case. we assume is type T
the function adds the first parameterwith the remaining operator by
using + operator between n1 and remaining arguements...


*/

template <typename... T>  //ellipsis

auto add(T... n1){
   // return (n1 + ...);  //rightmost arguments will be added first
    return (... + n1); // leftmost arguments will be added first
}


int main(){

   std::cout<< add<int>(1,2,3)<<"\n";   // 6
   std::cout<< add<int>(1)<<"\n";    // 1
   std::cout<< add<int>(1,2)<< "\n";   //3
}

/*
add(1,2,3,4,5)

1 + add(2,3,4,5)

*/