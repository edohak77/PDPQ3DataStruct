#include "../../include/linked_list/linked_list.hpp"

template<typename T>
int LinkedList<T>::FindElement(T element) {
    int counter = 0;
    LNode * current = head_;
    while (current != tail_){
        if(current->data_ == element){
            return counter;
        }
        current = current->next_;
        counter++;
    }

    return -1;
}

template<typename T>
void LinkedList<T>::AddToTail(T element) {
    LNode *current = new LNode(element);
    if(head_ == nullptr){
        head_ = new LNode(element);
        head_->next_ = tail_;
        head_->prev_ = nullptr;

        tail_ = new LNode(element);
        tail_->prev_ = head_;
        tail_->next_ = nullptr;
    } else if(tail_->prev_ == head_){
        head_->next_ = current;
        tail_->prev_ = current;

        current->prev_ = head_;
        current->next_ = tail_;
    } else{
        LNode *temp_tail_prev = tail_->prev_;
        tail_->prev_ = current;
        current->next_ = tail_;
        current->prev_ = temp_tail_prev;
        temp_tail_prev->next_ = current;
    }
    size_++;
}

template<typename T>
void LinkedList<T>::Insert(int index, T element) {

    if(index < 0 || index >= size_){
        throw "On Insert(): invalid index";
    }

    LNode *newLNode = new LNode(element);

    int counter = 0;
    LNode * current = head_;
    while (counter != index){
        current = current->next_;
        counter++;
    }

    LNode *current_temp_prev = current->prev_;
    current->prev_ = newLNode;
    newLNode->prev_ = current_temp_prev;
    newLNode->next_ = current;
    current_temp_prev->next_ = newLNode;

    size_++;
}

template<typename T>
T LinkedList<T>::GetAt(int index) {
    if(index < 0 || index >= size_){
        throw "On GetAt(): invalid index";
    }
    int counter = 0;
    LNode * current = head_;
    while (counter != index){
        current = current->next_;
        counter++;
    }

    return current->data_;
}

template<typename T>
int LinkedList<T>::Size() {
    return size_;
}

template<typename T>
bool LinkedList<T>::Empty() {
    return size_ == 0;
}

template<typename T>
T LinkedList<T>::operator[](int index) {
    return GetAt(index);
}

template<typename T>
void LinkedList<T>::Clear() {
    LNode *current = head_;
    while (current != nullptr){
        LNode *temp = current;
        current = current->next_;
        delete temp;
        if(current != nullptr){
            size_ --;
        }
    }
}

template<typename T>
void LinkedList<T>::RemoveByIndex(int index) {
    if(index < 0 || index >= size_){
        throw "Invalid index argument";
    }

    int counter = 0;
    LNode *current = head_;
    while (counter != index){
        current = current->next_;
        counter++;
    }

    if(current == head_){
        head_ = current->next_;
        head_->prev_ = nullptr;
        delete current;
    } else{
        LNode *temp_current_prev = current->prev_;
        current->next_->prev_ = temp_current_prev;
        temp_current_prev->next_ = current->next_;
        delete current;
    }
    size_--;
}

template<typename T>
void LinkedList<T>::RemoveElement(T element) {
    LNode *current = head_;
    while (current != tail_){
        if(current->data_ == element){
            LNode *temp_current_prev = current->prev_;
            if(temp_current_prev != nullptr) {
                current->next_->prev_ = temp_current_prev;
                temp_current_prev->next_ = current->next_;
                delete current;
                size_--;
                return;
            } else {
                current = nullptr;
                size_--;
                return;
            }

        }
        current = current->next_;
    }

    throw "Element not found";
}

template<typename T>
void LinkedList<T>::RemoveLast() {
    if(size_ == 1){
        delete head_;
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
    } else if(size_ == 2){
        delete head_->next_;
        head_->next_ = tail_;
        tail_->prev_ = head_;
    } else {
        LNode *temp_last_prev = tail_->prev_;
        tail_->prev_ = temp_last_prev->prev_;
        temp_last_prev->prev_->next_ = tail_;

        delete temp_last_prev;
    }

    size_ --;
}
