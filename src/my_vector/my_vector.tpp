#include "../../include/my_vector/my_vector.hpp"


template<typename T>
void MyVector<T>::Add(const T &el){
    if(size_ == buffer_size_){
        BuferGrow();
    }
    if( size_ < buffer_size_ && buffer_ != nullptr){
        buffer_[size_] = el;
        size_++;
        return;
    }
    throw "Can't add element";
}

template<typename T>
int MyVector<T>::Size() const{
    return size_;
}

template<typename T>
T MyVector<T>::operator[](int index) const {
    return GetAt(index);
}

template<typename T>
void MyVector<T>::BuferGrow() {
    int new_buffer_size = std::max(size_ * 2, INITIAL_BUFFER_SIZE);
    auto *new_buffer = new double [new_buffer_size];
    for (int i = 0; i < size_; ++i) {
        new_buffer[i] = buffer_[i];
    }

    delete [] buffer_;
    buffer_ = new_buffer;
    buffer_size_ = new_buffer_size;
}

template<typename T>
void MyVector<T>::DeleteLast() {
    BufferGoDown();
    --size_ ;

}

template<typename T>
T MyVector<T>::GetAt(int index) const {
    if( index >=0 && index < size_ && buffer_ != nullptr){
        return buffer_[index];
    }

    throw "Can't get element by index: " + std::to_string(index);
}

template<typename T>
void MyVector<T>::BufferGoDown() {

    if(size_ == 0){
        throw "ERROR";
    }

    int new_buffer_size = std::max(size_ * 2, INITIAL_BUFFER_SIZE);

    if(size_ != 0 && buffer_size_ / size_ >= 2 && buffer_size_ / size_ > INITIAL_BUFFER_SIZE){
        buffer_size_ = buffer_size_ / 2;
        auto *new_buffer = new double [new_buffer_size];
        for (int i = 0; i < size_; ++i) {
            new_buffer[i] = buffer_[i];
        }

        delete [] buffer_;
        buffer_ = new_buffer;
        buffer_size_ = new_buffer_size;
        if(size_ == 0){
            SetInitState();
        }
    }
}

template<typename T>
void MyVector<T>::SetInitState() {
    size_ = 0;
    buffer_ = nullptr;
    buffer_size_ = 0;
}

template<typename T>
void MyVector<T>::Clear() {
    delete [] buffer_;
    SetInitState();
}

template<typename T>
bool MyVector<T>::Empty() {
    return size_ == 0;
}
