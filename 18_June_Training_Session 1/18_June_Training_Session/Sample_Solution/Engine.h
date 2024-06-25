#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

class Engine
{
private:
    int engineId {0};
    int engineHorsepower{0};
    float engineTorque{0.0f};
public:
    Engine()=default;
    Engine(int id,int horsepower,float torque);
    ~Engine() {}
    Engine(const Engine& other)=delete;
    Engine(Engine&&)=delete;
    Engine& operator=(const Engine& other) = delete;
    

    int getEngineId() const { return engineId; }

    int getEngineHorsepower() const { return engineHorsepower; }

    float getEngineTorque() const { return engineTorque; }
};

#endif // ENGINE_H
