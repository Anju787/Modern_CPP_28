/*
amount = 10000


*/

#include <iostream>
#include <thread>
#include<mutex>

int32_t amount = {1000};
std::mutex mt;
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





int main(){

std::thread t1 {&withdraw};
std::thread t2 {&Deposit};

t1.join();
t2.join();
//syncronous single
//Deposit();
//withdraw();

for(int i =0;i<=50;i++){
std::cout<<amount<<"\n";
}

}


//reading from same memory is not problem but writing is
