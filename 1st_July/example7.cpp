#include <iostream>
#include <thread>
#include<mutex>

using ThreadContainer = std::list<std::thread>;

class BankOperations {

    private : 
    int32_t amount = {1000};
std::mutex mt;
void Deposit(){

public:


BankOperations(const BankOperations&) = default;
BankOperations(BankOperations&&) = delete;
BankOperations& operator = (const   BankOperations&) = delete;
BankOperations& operator = (    BankOperations&&) = delete;
BankOperations()= default;
BankOperations(int val) : m_value {val}  {}
~BankOperations ()= default;

void Deposit(){

for (int i =0; i<100;i++){
    
    std::this_thread:: sleep_for(std::chrono::milliseconds(5));
    mt.lock();
    amount += 10;
    mt.unlock();
}
}

void withdraw(){

for (int i =0; i<100;i++){
    std::this_thread:: sleep_for(std::chrono::milliseconds(5));
    mt.lock();
    amount -= 10;
    mt.unlock();
}
}
}

};


void CreateThreads(ThreadConatiner& threads, BankOperations b1){
    threads.emplace_back (&BankOPerations::Deposit, &b1);
    threads.emplace_back(&BankOPeratons::withdraw, &b1);

}

void  DisplayFinalAmount(BanKOperations b1){
    for(std::threads& th: threads)
{
    if(th.joinable()){
        th.join();

    }
}}

int main(){



    BankOperations b1 {5000};
ThreadContainer threads {};  //blank list if threads
    std::thread t1 { &BankOperations::Deposit, &b1};
       std::thread t2 { &BankOperations::Deposit, &b1};

       t1.join();
       t2.join();

       std::cout<<"final answer is :"<<b1.amount()<<"\n";



}


/*alias threadconatiner



*/

