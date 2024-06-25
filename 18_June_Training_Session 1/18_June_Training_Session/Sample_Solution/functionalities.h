#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include "IdNotFound.h"
#include "Nullptr.h"
#define size 4

void CreateEngines(Engine **eng);

float AverageHorsepower(Engine **eng);

float FindTorqueById(Engine **eng,int id);

int FindHorsepowerForMinTorqueEngine(Engine **eng);

void Deallocate(Engine **eng);

#endif // FUNCTIONALITIES_H
