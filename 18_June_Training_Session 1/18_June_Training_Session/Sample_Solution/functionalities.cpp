#include "functionalities.h"
#include <exception>

void CreateEngines(Engine **eng)
{
    for (int i = 0; i < size; i++)
    {
        int id,horsePower;
        float torque;

        std::cin>>id;
        std::cin>>horsePower;
        std::cin>>torque;

        eng[i] = new Engine(id,horsePower,torque);

    }
    
}



float AverageHorsepower(Engine **eng)
{
    if (size<0)
    {
        throw std::invalid_argument("Size is invalid");
    }

    int count=0;
    float total=0;
    for (int i = 0; i < size; i++)
    {
        if (eng[i])
        {
            count++;
            total+=eng[i]->getEngineHorsepower();
        }
    }

    if(count>0)    
    return total/count;

    return -1.0f;
}



float FindTorqueById(Engine **eng,int id)
{
      if (size<0)
    {
        throw std::invalid_argument("Size is invalid");
    }

    bool flag1=false;
    bool flag2=false;
    for (int i = 0; i < size; i++)
    {
        if(eng[i]){
        if (eng[i]->getEngineId()==id)
        {
            flag2 = true;
            return eng[i]->getEngineTorque();
        }
        flag1=true;
        }
    }

    if (!flag1)
    {
        throw NullPtr("invalid");
    }
    
    if (!flag2)
    {
        throw IdNotFound("Id not found");
    }
    return -1.0f;
}



int FindHorsepowerForMinTorqueEngine(Engine **eng)
{
     if (size<0)
    {
        throw std::invalid_argument("Size is invalid");
    }

    int idx=0,min=eng[0]->getEngineTorque();
    for (int i = 1; i < size; i++)
    {
        if (eng[i] && eng[i]->getEngineTorque()<min)
        {
            min=eng[i]->getEngineTorque();
            idx=i;
        }
    }
    return eng[idx]->getEngineHorsepower();
}



void Deallocate(Engine **eng)
{
    for (int i = 0; i < size; i++)
    {
        delete eng[i];
    }   
}
