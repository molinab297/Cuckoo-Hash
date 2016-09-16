// written by Blake Molina
// @molinab297@gmail.com

#ifndef CUCKOOHASH_CUCKOOTABLE_H
#define CUCKOOHASH_CUCKOOTABLE_H
#include <random>
#include <iostream>
#include "HashFunction.h"

/* Cuckoo Hash table implemented using two parallel arrays.
 *
 * Big O Facts:
 *
 * Insertions - succeed in expected constant time,[1] even considering the possibility
 * of having to rebuild the table, as long as the number of keys is kept below half
 * of the capacity of the hash table, i.e., the load factor is below 50%.
 *
 * Note - it is possible to increase the load factor up to 91 % before a rehashing
 * of the entire table is necessary. Using three hash functions instead of two
 * can achieve this.
 *
 * Lookups - Guaranteed Worst Case Scenario O(1) */

template <class Type>
class CuckooTable {

public:
    CuckooTable();
    CuckooTable(int tableSize);
    ~CuckooTable();

    void insert(Type key);
    bool lookup(const Type item);
    int  capacity() const;
    int  size() const;

    /*Return pointers to the beginning and end of the tables.
    As of right now two iterators are required for traversing
    the whole container, as this particular implementation of
    Cuckoo Hashing uses two different arrays for it's hash tables. */
    Type *begin_t1() const { return table_one; }
    Type *begin_t2() const { return table_two; }
    Type *end_t1() const { return table_one + (tableCapacity/2); }
    Type *end_t2() const { return table_two + (tableCapacity/2); }

    /* Custom iterator class for use with CuckooTable.
     * Use this class to iterate through the hash table. */
    class iterator {
    public:
        iterator(Type* init = 0 ) : current(init) {}
        Type& operator*() { return *current; } // dereference
        const Type& operator*() const { return current->data; }
        iterator& operator++() { // prefix
            if ( current ) current++;
            return *this;
        }
        iterator operator++(int) { // postfix
            iterator temp = *this;
            ++*this;
            return temp;
        }
        bool operator==(const iterator& x) const { return current == x.current; }
        bool operator!=(const iterator& x) const { return current != x.current; }

    private:
        Type* current;
    };


private:
    Type *table_one;
    Type *table_two;

    HashFunction f; // hash function for table 1
    HashFunction g; // hash function for table 2

    int tableCapacity;
    int tableSize;

    void initializeTable(Type ar[], const int SIZE);
};


template <class Type>
CuckooTable<Type>::CuckooTable() {
    tableCapacity = 20;
    tableSize = 0;

    /* divide the table into two tables of equal size
     * and initialize both tables to 0 */
    table_one = new Type[tableCapacity/2];
    table_two = new Type[tableCapacity/2];
    initializeTable(table_one, tableCapacity/2);
    initializeTable(table_two, tableCapacity/2);

    f.setTableCapacity(tableCapacity/2);
    g.setTableCapacity(tableCapacity/2);
    g.setMultiplier(3);

}

template <class Type>
CuckooTable<Type>::CuckooTable(int tableCapacity) {
    this->tableCapacity = tableCapacity;
    tableSize = 0;

    /* divide the table into two tables of equal size
 * and initialize both tables to 0 */
    table_one = new Type[tableCapacity/2];
    table_two = new Type[tableCapacity/2];
    initializeTable(table_one, tableCapacity/2);
    initializeTable(table_two, tableCapacity/2);

    f.setTableCapacity(tableCapacity/2);
    g.setTableCapacity(tableCapacity/2);
    g.setMultiplier(3);
}


template <class Type>
CuckooTable<Type>::~CuckooTable() { delete [] table_one; delete [] table_two; }

template <class Type>
void CuckooTable<Type>::insert(Type key)
{
    bool found    = false;
    int  loopCount = 0;

    if(lookup(key))
        return;
    else
    {
        while(loopCount < 16 && !found)
        {
            // if index at table 1 is empty, insert key
            if(table_one[f.getHash(key)] == 0)
            {
                table_one[f.getHash(key)] = key;
                found = true;
                tableSize++;
            }
            else
            {
                // evict value at taken spot and insert new value
                Type evictedValue = table_one[f.getHash(key)];
                table_one[f.getHash(key)] = key;
                // make the evicted value the new value to find a spot in the table for
                key = evictedValue;

                // if index at table 2 is empty, insert key
                if(table_two[g.getHash(key)] == 0)
                {
                    table_two[g.getHash(key)] = key;
                    found = true;
                    tableSize++;
                }
                else
                {
                    // evict value at taken spot and insert new value
                    evictedValue = table_two[g.getHash(key)];
                    table_two[g.getHash(key)] = key;
                    // make the evicted value the new value to find a spot in the table for
                    key = evictedValue;

                    loopCount ++;
                }

            }
        }

        if(loopCount == 16)
            std::cout << "\nCycle encountered.\n";
    }

}

template <class Type>
bool CuckooTable<Type>::lookup(const Type item)
{
    if(table_one[f.getHash(item)] == item)
        return true;
    if(table_two[g.getHash(item)] == item)
        return true;

    return false;
}

template <class Type>
int CuckooTable<Type>::capacity() const {
    return tableCapacity;
}

template <class Type>
int CuckooTable<Type>::size() const {
    return tableSize;
}

template<class Type>
void CuckooTable<Type>::initializeTable(Type ar[], const int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        ar[i] = 0;
    }
}

#endif //CUCKOOHASH_CUCKOOTABLE_H
