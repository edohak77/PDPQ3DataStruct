#ifndef PDP_Q3_2020_HASH_TABLE_AO_HPP
#define PDP_Q3_2020_HASH_TABLE_AO_HPP
#include <string>
#include "cmath"

const int VAL = 2;
const std::string EMPTY_STRING = "";

//Collisions are resolved by open addressing  method by double hashing
class HashTable_AO{
 public:
    HashTable_AO();
    ~HashTable_AO(){ delete [] base_array_; }
    void Add(const std::string &element);
    void Remove(const std::string & element);
    bool Contains(const std::string & element);
    int Size() const;
    bool Empty() const;
    int GetTableSize();
private:
    int table_size_;
    int size_;
    std::string *base_array_;
    long int StrToInt(const std::string &str);
    int GetHash(const std::string &str,int i);
    int Hash1(const std::string &element);
    int Hash2(const std::string &element);
};


#include "../../src/hash_table/hash_table_OA.tpp"
#endif //PDP_Q3_2020_HASH_TABLE_AO_HPP
