#include "functionalities.h"

void CreateEngines(std::vector<Engine *> &eng)
{
    //whatever you write in emplace back, it should be "suffient material"
    //to make a new instance for the container of that specific type

    //type :  vector of Engine pointers---> we need materials to make a new Engine* 
    eng.emplace_back(new Engine(101,574,120.0f));
    eng.emplace_back(new Engine(102,590,140.0f));
    eng.emplace_back(new Engine(103,374,150.0f));
}

float AverageHorsepower(const std::vector<Engine *> &eng)
{
    if (eng.size()<=0)
    {
        throw std::invalid_argument("Size is invalid");
    }
    
    float total {0.0f};
    std::size_t count {0};

    //range-based for loop
    /*
        for each const Engine pointer "called e" present in engines
    */
    for(const Engine* e : eng){
        if(e){
        total+=e->getEngineHorsepower();
        count++;
        }
    }

    if(count==0){
        throw NoValidPointer("No Valid element found");
    }
    return total/count;

}

float FindTorqueById(const std::vector<Engine *> &eng, int id)
{
     if (eng.size()<=0)
    {
        throw std::invalid_argument("Size is invalid");
    }

    bool flag {false};
    for(const Engine* e : eng){
        if(e){
        if(e->getEngineId()==id){
        return e->getEngineTorque();
        }
        flag=true;
        }
    }

  if (!flag)
  {
    throw NoValidPointer("Invalid pointer");
  }

  throw IdNotFound("Id not found");
  
}

int FindHorsepowerForMinTorqueEngine(const std::vector<Engine *> &eng)
{
     if (eng.size()<=0)
    {
        throw std::invalid_argument("Size is invalid");
    }

    bool flag {false};
    float min {eng[0]->getEngineHorsepower()}; 
    unsigned int idx {-1};
    unsigned int k {0};
    for(const Engine* e : eng){
        if(e){
        if(e->getEngineHorsepower()<min){
            min=e->getEngineHorsepower();
            idx=k;
        }
        flag=true;
        }
        k++;
    }

  if (!flag)
  {
    throw NoValidPointer("Invalid pointer");
  }

    return eng[idx]->getEngineHorsepower();
}
