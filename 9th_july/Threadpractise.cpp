#include <iostream>
#include <thread>
#include <vector>

//threds cannot be copied so passed by reference
class Dummy {
    private :


    public:
Dummy(){}
~Dummy(){}

void DisplayFactorial (unsigned int val){
    if (val==1 || val==0){
        std::cout<<1<<"\n";
    }

    else {
        unsigned int result{1};
        for(unsigned int i =2;i<=val;i++){

        }
    }

    static void MultipleBy100(int number){
        std::cout<<"number *100";
    }
void Sqaure(int number){
    std::cout<<number * number;
}

}

};

void MapThreads(std::vector<std::thread>& threads){
    threads [0] = std::thread(&Square, 10);
}

int main(){
    auto f1=[] (int number){std::cout<<number * number * number;};
    std::vector<std::thread> threads{};
}


//in threads we use lock unlock  and prefereabbly lock guard 
// std::lock_guard<std::mutex> lt(mt)
// in the header file add <mutex>  and down describe mutex like :   std::mutex mt

// use -lpthread for the terminal command
//threds can so things parallely but cannot show the results
//so for this we will use async threads


// async thread - to create aync thread  :   std::future<int> res1 = std::async (&Square, 10);
//                                                for sync   result                variable, parameter

    //static variables are not part of local function scope