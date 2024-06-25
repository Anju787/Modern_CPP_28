#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include "IdNotFound.h"
#include "Nullptr.h"
#include <vector>
#include "NoValidPointer.h"


using  Container=std::vector<Engine*>;

void CreateEngines(Container& eng);

float AverageHorsepower(const Container& eng);

float FindTorqueById(const Container& eng,int id);

int FindHorsepowerForMinTorqueEngine(const Container& eng);


#endif // FUNCTIONALITIES_H
