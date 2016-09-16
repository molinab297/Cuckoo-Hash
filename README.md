# Cuckoo-Hash
Cuckoo Hash implementation in c++. Guarantees worst case lookup O(1).

![Alt text](http://www.thebritishbirds.com/sites/thebritishbirds.com/files/birds/cuckoo-bird.jpeg?1307346614 "Optional title")

Cuckoo Hashing uses an Open Addressing scheme in which two separate hash tables with two separate hash functions are used for inserting elements.
It applies the idea of multiple-choice and relocation together and guarantees O(1) worst case lookup time! Insertions succeed in expected constant time, O(1), even considering the possibility of having to rebuild the table, as long as the number of keys is kept below half of the capacity of the hash table, i.e., the load factor is below 50%. (With three hash functions the load factor is greatly increased to about 91% ... However this implemenation only uses two). 

For more info on the algorithm - https://en.wikipedia.org/wiki/Cuckoo_hashing

# Change Log

Version 1.1
- added support for templates; can now hash strings, chars, and ints
- added custom iterator which can used to traverse the map


Version 1.0
- Initial push


