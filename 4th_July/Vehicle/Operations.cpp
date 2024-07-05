#include "Operations.h"
#include <iostream>
DataContainer Operations::m_data{};
ThreadContainer Operations::m_threads{};
std::mutex Operations::mt{};

void Operations::CreateCarsAndBikes()
{
    m_data.emplace_back(new Bike("12",900.0f));
    m_data.emplace_back(new Car("13",5678.0f,5));
    //v.emplace_back("34")

}

void Operations::FindAverageCost()
{
    if(m_data.empty()){
        mt.lock();
        std::cerr<<"empty data container \n";
        mt.unlock();
    }
    float total{0.0f};

    for(const VrType v:m_data){
        std::visit([&](auto&& val){total+=val->price();},v);
    }
    if(!m_data.empty()){
        std::cout<<"average total cost is:"<< total/m_data.size() <<"\n";
    }
}
std::optional<VrType> Operations::ReturnMatchingInstance(std::string id)
{
    if(m_data.empty()){
        std::cerr<<"empty data container \n";
    }
    std::optional<VrType>result{std::nullopt};
    bool m_id_found{false};
    for(const VrType v:m_data){
        std::visit(
            [&](auto&& val){if (val->id()==id){result=v;}},v);
        if(m_id_found){
            break;
        }
        
    }
    return result;
}

void Operations::Deallocate()
{
    if(m_data.empty()){
        std::cerr<<"empty data container \n";
    }
    for(const VrType v:m_data){
        std::visit(
            [](auto&& val){delete val;},v);
    }
}

void Operations::DisplayInsuranceCost()
{
    //std::visit( [](auto&& data) {std::cout <<data-> <<"\n"; }, v);
    if(m_data.empty()){
        mt.lock();
        std::cerr<<"empty data container \n";
        mt.unlock();
    }
    for(const VrType v:m_data){
        std::visit(
            [](auto&& val){mt.lock() ;
            std::cout<<val->InsuranceAmount()<<"\n";
            mt.unlock();},v);
    }
}

std::optional<unsigned int> Operations::FindSeatCountById(std::string id)
{
    if(m_data.empty()){
        std::cerr<<"empty data container \n";
    }
    std::optional<unsigned int>result{std::nullopt};
    bool matchFound{false};
    for(const VrType v:m_data){
        if(std::holds_alternative<Car*>(v)){

            Car* temp=std::get<0>(v);

            if(temp->id()==id){
                matchFound=true;
                result=temp->seatCount();

            }
        }
    }
    if(!matchFound && !m_data.empty()){
        std::cerr<<"No match found"<<"\n";



    }
    return result;
}

void Operations::MapThread()
{
    m_threads.emplace_back( Operations::FindAverageCost );
    //m_threads.emplace_back(Operations::ReturnMatchingInstance,"12" );
    m_threads.emplace_back(Operations::DisplayInsuranceCost );
}

void Operations::JoinThread()
{
    for(std::thread& th:m_threads){
        if(th.joinable()){
            th.join();
        }
    }
}
