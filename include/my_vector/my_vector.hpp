#ifndef PDP_Q3_2020_MY_VECTOR_HPP
#define PDP_Q3_2020_MY_VECTOR_HPP

    const int INITIAL_BUFFER_SIZE = 8;

    template<typename T>
    class MyVector {
    public:

        //Constructor
        MyVector() {SetInitState();}

        //Destructor
        virtual ~MyVector() { delete[] buffer_; }

        //Add element to end of array
        void Add(const T &el);

        //Get element by index
        T GetAt(int index) const;

        //Get my vector size
        int Size() const;

        //Delete last element
        void DeleteLast();

        // Remove all element from MyVector
        void Clear();

        // Return MyVector is empty or no
        bool Empty();

        // operator []
        T operator[](int index) const;

    private:
        T *buffer_;
        int buffer_size_;
        int size_;

        void BuferGrow();
        void BufferGoDown();
        void SetInitState();
    };

#include "../../src//my_vector/my_vector.tpp"
#endif //PDP_Q3_2020_MY_VECTOR_HPP
