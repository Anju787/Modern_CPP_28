/*
1) CreateCarsAndOperationss
2)FindAverageCostOfVehicles : print the average price of all vehicles in our database
3)ReturnMatchingInstance : return the first vehicle wjose id matches wth the id parameter received
4) Deallocate : release heap allocations if any!
5)DisplayInsuranceAmount : show output of Insurance function for each instance
6) FindSeatCountForGivenId : features vehicle based on id and return coressponding seat_count
*/

#include "Bike.h"
#include "Car.h"

#include <iostream>
#include <variant>
#include <list>
#include <functional>
#include <thread>
#include <mutex>

std::mutex mt;

using VrType =std::variant<Car*, Bike*>;
using ThreadContainer= std::list<std::thread>;
using DataContainer = std::list<VrType>;
class Operations {

    private :

static DataContainer m_data;
static ThreadContainer thread;
//initiliasation of static memeber cannot be initialised in .h file but in cpp file

    public:


    Operations () = delete;
    Operations (const Operations&) = delete;  
    Operations(Operations&&) = delete;
    Operations& operator = (const Operations&) = delete;
    Operations& operator=(Operations&&)= delete;

    ~Operations()= default;

static  void CreateCarsAndBikes(DataContainer& data);

/*
FindAverage : Use visit function to do this. Both car and bike have a m_price attribute.
We can use tgheir getter function to calculate cost


ReturnMatchingInstance : Variant whose id matched with the id passed


*/


static void FindAverageCost();

std::optional<VrType>  ReturnMatchInstance(std::string id);
void Deallocate();

void DisplayInsuranceAmount();

/*
scenario 1 : id found, matches iwth car, seat count returned
2. : id found , matches with a bike ---> nullptr
3. id not found : nullptr
*/

static std::optional <VrType>FindSeatCountForGivenId();


//left 
static void MapThreads();
static void JoinThreads();

   
};