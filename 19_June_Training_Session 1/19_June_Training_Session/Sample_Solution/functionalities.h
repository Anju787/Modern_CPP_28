#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include "IdNotFound.h"
#include "Nullptr.h"
#include <vector>
#include "NoValidPointer.h"

void CreateEngines(std::vector<Engine*>& eng);

float AverageHorsepower(const std::vector<Engine*>& eng);

float FindTorqueById(const std::vector<Engine*>& eng,int id);

int FindHorsepowerForMinTorqueEngine(const std::vector<Engine*>& eng);


#endif // FUNCTIONALITIES_H
