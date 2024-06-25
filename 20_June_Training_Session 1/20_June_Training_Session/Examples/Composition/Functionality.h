#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include "BankAccount.h"
#include "AccountNotFound.h"
#include <stdexcept>
#include <vector>
#include "NumberNotFound.h"
#include "NoValidPointer.h"

using Container=std::vector<BankAccount*>;
 
void CreateObjects(Container &accounts);

void DisplayDebitCardDetails(const Container &accounts,long number);

void CountVISACards(Container &accounts);

void Deallocation(Container &accounts);

#endif // FUNCTIONALITY_H
