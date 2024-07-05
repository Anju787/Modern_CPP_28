/*
 1) CreateCarsAndBikes
 2) FindAverageCostOfVehicles : return the average price of all vehicles in our database
 3) ReturnMatchingInstance: return the first vehicle whose id matches with the
 id parameter received
 4) Deallocate: release heap allocations if any!
 5)  DisplayInsurance: show output of InsuranceAmount function for each instance.
 6) FindSeatCountForGivenId: fetches vehicle based on D
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <list>
#include <iostream>
#include "Car.h"
#include "Bike.h"
#include <variant>
#include <optional>
#include <thread>
#include <mutex>

using VrType=std::variant<Car*, Bike*>;
using DataContainer=std::list<VrType>;
using ThreadContainer=std::list<std::thread>;

class Operations
{
private:
    /* data */
   static DataContainer m_data;
   static ThreadContainer m_threads;
   static std::mutex mt;
public:
    Operations()=delete;
    Operations(const Operations&)=delete;
    Operations(Operations&&)=delete;
    Operations& operator=(const Operations&)=delete;
    Operations& operator=(Operations&&)=delete;
    ~Operations()=default;

    static void CreateCarsAndBikes();


    /*
     FindAverageCost: Use visit function to do this. Both Car and Bike have a m_price
     attribute. We can use their getter function to calculate total.
    */
    static void FindAverageCost();


   /* 
     Return MatchingInstance: Variant whose ID matches with the id passed
   */
  static std::optional<VrType> ReturnMatchingInstance(std::string id);
   

   static void Deallocate();

   static void DisplayInsuranceCost();

   /*
    scene1: id found,matches with a car, seat count returned
    scene2: id found,matches with a bike ---->nullopt
    scene3: id not found :nullopt.
   */

    static std::optional<unsigned int>  FindSeatCountById(std::string id);

   static void MapThread();
   static void JoinThread();




};

#endif // OPERATIONS_H
