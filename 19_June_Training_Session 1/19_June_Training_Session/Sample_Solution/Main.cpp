#include "functionalities.h"

int main(){
    std::vector<Engine*> engine;
    CreateEngines(engine);

    try
    {
        AverageHorsepower(engine);
    }
    catch(const NoValidPointer& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        FindTorqueById(engine,101);
    }
    catch(const NoValidPointer& e)
    {
        std::cerr << e.what() << '\n';
    }catch(const IdNotFound& e){

        std::cerr << e.what() << '\n';
    }

    try
    {
        FindHorsepowerForMinTorqueEngine(engine);
    }
    catch(const NoValidPointer& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    
    
    

}