#include "functionalities.h"

int main(){
    Engine *eng[4];
    // CreateEngines(eng);
    eng[0]=nullptr;
    eng[1]=nullptr;
    eng[2]=nullptr;
    eng[3]=nullptr;
    try{
        std::cout<<FindTorqueById(eng,192)<<"\n";
    }catch(NullPtr & e){
        std::cerr<<e.what()<<"\n";
    }
     try{
        std::cout<<AverageHorsepower(eng)<<"\n";
    }catch(NullPtr & e){
        std::cerr<<e.what()<<"\n";
    }catch(std::invalid_argument& e){
        std::cerr<<e.what();
    }
    
    
    std::cout<<FindTorqueById(eng,192)<<"\n";
    std::cout<<FindHorsepowerForMinTorqueEngine(eng)<<"\n";
    Deallocate(eng);

}