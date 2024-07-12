//  if you access wrong index of variant, it will give bad index varaint access


#include <iostream>
#include <variant>

#include<cctype>

using vrType= std::variant <int, std::string>;


//possible on all types for the variant
void DisplayValue(vrType& v){
    std::visit([](auto&& val){
        std::cout<<val<<"\n";
    }, v);

}


void ConvertToUpper(vrType& v){
    if (std::holds_alternative<std::string>(v)){
        std::string temp = std::get<1>(v);
        for(char& c :temp){
            std::cout<<char((int)c - 32);
        }
    }

}