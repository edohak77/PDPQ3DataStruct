#ifndef PDP_Q3_2020_HASH_TABLE_HPP
#define PDP_Q3_2020_HASH_TABLE_HPP
#include "cmath"
#include "../linked_list/linked_list.hpp"


const int PARAM_ = 2;
const int TABLE_SIZE = 256;

//Collisions are resolved by a linked method
class HashTable_LC{
 public:
    HashTable_LC();
    int GetHash(const std::string &str);
    void Add(const std::string &element);
    void Remove(const std::string & element);
    bool Contains(const std::string & element);
    int Size();
    bool Empty();
private:
    int size_;
    LinkedList<const std::string&> *base_array_[TABLE_SIZE];
    void AddIfNotCollision(const std::string &element, int hash);
    void AddWithCollision(const std::string &element, int hash);
};




#include "../../src/hash_table/hash_table.tpp"
#endif //PDP_Q3_2020_HASH_TABLE_HPP
