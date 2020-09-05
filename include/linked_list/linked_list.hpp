#ifndef PDP_Q3_2020_LINKED_LIST_HPP
#define PDP_Q3_2020_LINKED_LIST_HPP

    template<typename T>
    class LinkedList {
        struct LNode {
            T data_;
            LNode *next_;
            LNode *prev_;

            LNode(T data) : data_(data) {}
        };

        LNode *head_;
        LNode *tail_;
        int size_;

    public:

        //Constructors
        LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

        //Find element and returned index of element or -1
        int FindElement(T element);

        //Add element ot list tail
        void AddToTail(T element);

        //Add element by index
        void Insert(int index, T element);

        //Get element by index
        T GetAt(int index);

        void RemoveByIndex(int index);

        void RemoveElement(T element);

        void RemoveLast();

        //Get list size
        int Size();

        //Return list is empty or no
        bool Empty();

        // Clear list
        void Clear();

        //operator []
        T operator[](int index);

    };
#include "../../src/linked_list/linked_list.tpp"

#endif //PDP_Q3_2020_LINKED_LIST_HPP
