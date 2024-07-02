
// /*

// Terminologies

// 1) CPU : Set of hardware responsible for executing tasks in a computing system

// 2) System : Any computing device

// 3) Processor : Hardware chip(made of silicon) designed
// for executing instructions given bye the user of the computer
// e.g :intel i7

// 4) Socket : point on the motherbaord where processor is connected

// 5) COre: every processor is divided internally into units called  as COres
// Each core execute instructions from one processat any given time

// 6)Process : A running task on the system



// */

// #include <iostream>
// #include <vector>
// #include <functional>
// #include <thread>
// #include <mutex> //binary semaphore

// std::mutex mt;

// using Operation = std::function<int(int number)>;

// void Adaptor(Operation fn, const std::vector<int> &data)
// {
//     for (int val : data)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         fn(val); // apply function on a single item , repeat this in a loop
//     }
// }
// void Square(int number)
// {
//     mt.lock(); // ask for thr permission to access cout

//     std::cout << number * number; // critical section
//     mt.unlock();                  // release the lock when done
// }

// int main()
// {

//     auto cube_fn = [](int number)
//     {
//         mt.lock();
//         std::cout << number * number * number;
//         mt.unlock();
//     };

//     //
//     std::thread t1{&Adaptor, &Square, std::vector<int>{1, 2, 3, 4, 5}}, 0;

//     std::thread t2{&Adaptor, &cube_fn, std::vector<int>{1, 2, 3, 4, 5}, 5};

//     t1.join(); // main cannot proceed beyond line 54 unless t1 is terminated/completed

//     t2.join(); // main cannot proceed beyond line 56 unless t1 is terminated/completed

//     for (int val : result)
//     {
//         std::cout << val << "\n";
//     }
// }
///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////KT

/*
 
  Terminologies:
 
  1)CPU : Set of hardware responsible for executing tasks in a computing system
 
  2)System : Any computing device
 
  3)Processor : A hardware chip (made of silicon) designed for executing
  insructions given by the user of the computer
 
  4)Socket : Point on the motherboard where processor is connected
 
  5)Core : Every processor is divided internally into units called as "Cores"
  Each core can execute instructions from one "process" at any given time
 
  6)processor : hardware chip designed for executing instructions
 
 //order of execution is not dependent 
 
*/
 
#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <mutex> //ordinary  binary semaphore
 
std::mutex mt;
 
using Operations = std::function<void(int number)>;
 
void Adaptor(Operations fn, const std::vector<int> &data)
{
    for (int val : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        fn(val); // apply function on a single item. Repeat this in a loop
    }
}
 
void Square(int number)
{
    mt.lock();                            // ask for the permission to use cout
    std::cout << number * number << "\n"; // critical section
    mt.unlock();                          // release the lock when done
}
 
 
int main()
 
{
 
    auto cube_fn = [](int number)
    {
        mt.lock();
        std::cout << number * number * number << "\n";
        mt.unlock();
    };
 
    // execute Adaptor function by using Square function and vector of values
    // as its parameters
 
    std::thread t1{&Adaptor, &Square, std::vector<int>{1, 2, 3, 4, 5}};
    std::thread t2{&Adaptor, cube_fn, std::vector<int>{1, 2, 3, 4, 5}};
 
    t1.join();
    t2.join();
}