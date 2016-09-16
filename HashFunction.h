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
    int getHash(const char* value);

private:
    int multiplier;
    int tableCapacity;
};


#endif //CUCKOOHASH_HASHFUNCTIONS_H
