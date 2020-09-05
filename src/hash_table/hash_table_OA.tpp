#include <iostream>
#include "../../include/hash_table/hash_table_OA.hpp"

HashTable_AO::HashTable_AO() {
    table_size_ = 256;
    size_ = 0;
    base_array_ = new std::string [table_size_];
}

int HashTable_AO::GetHash(const std::string &str, int i) {
    int hash = (Hash1(str) + (i * Hash2(str)))%table_size_;
    return hash;
}

long int HashTable_AO::StrToInt(const std::string &str) {
    if(str.empty()){
        throw "element can't be empty";
    }
    long int hash = 0;
    int pov_n = 0;
    for (int i = 0; i < str.size(); ++i) {
        int current_param = pow(VAL, pov_n);
        hash += str.at(i) * current_param;
        pov_n++;
    }

    return (hash);
}

int HashTable_AO::Hash1(const std::string &str) {
   long int hash = StrToInt(str);
    return hash % table_size_;
}

int HashTable_AO::Hash2(const std::string &str) {
    long int k = StrToInt(str);
    int hash = k % (table_size_ - 1) + 1;
    return hash;
}

void HashTable_AO::Add(const std::string &element) {
    bool isAdd = false;

    for (int i = 0; i < table_size_; ++i) {
        int hash = GetHash(element, i);
        if(base_array_[hash].empty()){
            base_array_[hash] = element;
            size_ ++;
            isAdd = true;
            return;
        }
    }
    if(!isAdd){
        // There is can be function for table grow
        throw "Table is full....";
    }
}

void HashTable_AO::Remove(const std::string &element) {
    for (int i = 0; i < table_size_; ++i) {
        int hash = GetHash(element, i);
        if(base_array_[hash] == element){
            base_array_[hash] = EMPTY_STRING;
            size_ --;
            return;
        }
    }
    throw "Element " + element + " not exist";
}

bool HashTable_AO::Contains(const std::string &element) {
    for (int i = 0; i < table_size_; ++i) {
        int hash = GetHash(element, i);
        if(base_array_[hash] == element){
            return true;
        }
    }
    return false;
}

int HashTable_AO::Size() const {
    return size_;
}

bool HashTable_AO::Empty() const {
    return size_ == 0;
}

int HashTable_AO::GetTableSize() {
    return table_size_;
}
