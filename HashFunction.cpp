#include "HashFunction.h"

HashFunction::HashFunction()
{
    multiplier     = 1;
    tableCapacity  = 0;
}

HashFunction::HashFunction(int size)
{
    multiplier     = 1;
    tableCapacity  = size;
}

HashFunction::~HashFunction() {

}

void HashFunction::setMultiplier(const int product)
{
    multiplier = product;
}

void HashFunction::setTableCapacity(const int capacity)
{
    tableCapacity = capacity;
}

void HashFunction::setMultiplierAndCapacity(int product, int capacity)
{
    multiplier = product;
    tableCapacity = capacity;
}

int HashFunction::getHash(const int value)
{
    return (multiplier*value)%(tableCapacity-1);
}

int HashFunction::getHash(const std::string value)
{
    int intFromString = 0;
    for(int i = 0; i < value.size(); i++)
    {
        intFromString += value[i];
    }
    return tableCapacity - ((multiplier*intFromString)%(tableCapacity-1));
}

int HashFunction::getHash(const char value)
{
    return (multiplier*value)%(tableCapacity-1);
}

int HashFunction::getHash(const char* value)
{
    int intFromCharAr = 0;
    for(int i = 0; i < sizeof(value)/sizeof(char); i++)
    {
        intFromCharAr += value[i];
    }
    return tableCapacity - ((multiplier*intFromCharAr)%(tableCapacity-1));
}