#include "CuckooTable.h"

int main()
{
    // Construction example using ints.
    CuckooTable<int> table(50);

    // Insertion example
    table.insert(5);   table.insert(10);
    table.insert(20);  table.insert(3);
    table.insert(17);  table.insert(25);
    table.insert(444); table.insert(199);
    table.insert(299); table.insert(311);
    table.insert(566); table.insert(151);
    table.insert(777); table.insert(1010);
    table.insert(999); table.insert(221);
    table.insert(132); table.insert(123);


    // Printing out the Cuckoo Table #1 example using custom Iterator class
    std::cout << "Table One : \n";
    for(CuckooTable<int>::iterator it = table.begin_t1(); it != table.end_t1(); ++it)
    {
        if(*it == 0)
            std::cout << " - ";
        else
            std::cout << *it << " ";
    }

    // Printing out the Cuckoo Table #2 example using custom Iterator class
    std::cout << "\n\nTable Two : \n";
    for(CuckooTable<int>::iterator it = table.begin_t2(); it != table.end_t2(); ++it)
    {
        if(*it == 0)
            std::cout << " - ";
        else
            std::cout << *it << " ";
    }

    return 0;
}