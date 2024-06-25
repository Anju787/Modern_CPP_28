/*
create an adaptor which accpets
a) a data container of string values

b) a function with the following signature
i) input parameter : one string by lvalue reference 
ii) output : void

Adaptor should be used to perform operations on string values which are:
1- identify
2- printf the last 3 characters of each string
3- print the first non - vowel character of each string

*/


#include <iostream>
#include <vector>
#include <functional>


using Logic = std::function<void (const std::string&)>;
using DataContainer = std::vector<std::string>;

void Adaptor (const Logic fn, const DataContainer& data) {
    if(data.empty())
    {
        throw std::invalid_argument("No container Found!\n");
    }
    for(const std::string& st : data){
        fn(st);


    }
}

void FindVowels(const std::string& val){
    if(val==""){
        std::cerr<<"cannot find vowel\n";
        return;
    }

    bool atleastOneVowelFound {false};

    for(char c: val){
        if(c== 'A' || c=='a'|| c=='E' || c=='e' || c=='i' || c =='I' || c=='o' || c=='O' || c=='u' || c=='U' )  {

atleastOneVowelFound = true;
std::cout<<c<<"\n";
        }
    }

    if(atleastOneVowelFound){
        std::cerr<<"vowel not found \n";

    }
}

int main(){

    std::vector<std::string> data1 {"", "abc", "xyz", "mno"};

    std::vector<std::string> data2 {"", " ", " ", " "};

    std::vector<std::string> data3 {};

    try {

        Adaptor(&FindVowels, data1);
          Adaptor(&FindVowels, data2);
            Adaptor(&FindVowels, data3);

    }

    catch (std::invalid_argument& ex){
        std::cerr<<ex.what()<<"\n";


    }

}




