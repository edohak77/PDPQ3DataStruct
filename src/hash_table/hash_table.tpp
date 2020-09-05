#include <string>
#include "../../include/hash_table/hash_table.hpp"

HashTable_LC::HashTable_LC() {
    for (auto & i : base_array_) {
        i = nullptr;
    }
    size_ = 0;
}

int HashTable_LC::GetHash(const std::string &str) {
    if(str.empty()){
        throw "element can't be empty";
    }
    long int hash = 0;
    int pov_n = 0;
    for (char i : str) {
        int current_param = pow(PARAM_, pov_n);
        hash += i * current_param;
        pov_n++;
    }

    return (hash % TABLE_SIZE);
}

void HashTable_LC::Add(const std::string &element) {

    int hash = GetHash(element);
    if(base_array_[hash] == nullptr){
        AddIfNotCollision(element, hash);
    } else {
        AddWithCollision(element, hash);
    }

    size_++;
}

void HashTable_LC::Remove(const std::string &element) {

    if( size_ == 0){
        throw "Hash table is empty....";
    }

    int hash = GetHash(element);
    if(base_array_[hash] == nullptr){
        throw "Element '" + element +"' does not exist";
    }

    if(base_array_[hash]->FindElement(element) == -1){
        throw "Element '" + element +"' does not exist";
    }

    base_array_[hash]->RemoveElement(element);
    if(base_array_[hash]->Size() == 0){
        base_array_[hash] = nullptr;
    }
    size_ --;
}

bool HashTable_LC::Contains(const std::string &element) {
    int hash = GetHash(element);

    if(base_array_[hash] == nullptr){
        return false;
    }

    if(base_array_[hash]->FindElement(element) == -1){
        return false;
    }

    return true;
}

int HashTable_LC::Size() {
    return size_;
}

void HashTable_LC::AddIfNotCollision(const std::string &element, int hash) {
    base_array_[hash] = new LinkedList<const std::string&>;
    base_array_[hash]->AddToTail(element);
}

void HashTable_LC::AddWithCollision(const std::string &element, int hash) {
    base_array_[hash]->AddToTail(element);
}

bool HashTable_LC::Empty() {
    return size_ == 0;
}


