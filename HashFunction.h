// written by Blake Molina
// @molinab297@gmail.com

#ifndef CUCKOOHASH_HASHFUNCTIONS_H
#define CUCKOOHASH_HASHFUNCTIONS_H

#include <random>
#include <iostream>


/* Generates a hash function depending on the type of data being hashed.
 * Note: Setting the table capacity for a hash function object is necessary.
 * This allows the hash function value to not exceed the size of the hash table.
*/
template <class Type>
class HashFunction
{
public:
    HashFunction();
    HashFunction(int tableCapacity);
    ~HashFunction();

    void setMultiplier(const int product);
    void setTableCapacity(const int capacity);
    void setMultiplierAndCapacity(int product, int capacity);

    int getHash(const int value);
    int getHash(const std::string value);
    int getHash(const char value);

private:
    int multiplier;
    int tableCapacity;
};

template <class Type>
HashFunction<Type>::HashFunction()
{
    multiplier     = 1;
    tableCapacity  = 0;
}

template <class Type>
HashFunction<Type>::HashFunction(int size)
{
    multiplier     = 1;
    tableCapacity  = size;
}

template <class Type>
HashFunction<Type>::~HashFunction() {

}

template <class Type>
void HashFunction<Type>::setMultiplier(const int product)
{
    multiplier = product;
}

template <class Type>
void HashFunction<Type>::setTableCapacity(const int capacity)
{
    tableCapacity = capacity;
}

template <class Type>
void HashFunction<Type>::setMultiplierAndCapacity(int product, int capacity)
{
    multiplier = product;
    tableCapacity = capacity;
}

template <>
int HashFunction<int>::getHash(const int value)
{
    return (multiplier*value)%(tableCapacity-1);
}

template <>
int HashFunction<std::string>::getHash(const std::string value)
{
    int intFromString = 0;
    for(int i = 0; i < value.size(); i++)
    {
        intFromString += value[i];
    }
    return tableCapacity - ((multiplier*intFromString)%(tableCapacity-1));
}

template <>
int HashFunction<char>::getHash(const char value)
{
    return (multiplier*value)%(tableCapacity-1);
}


#endif //CUCKOOHASH_HASHFUNCTIONS_H
