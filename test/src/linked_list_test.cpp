#include "../lib/catch2/catch.hpp"
#include "../../include/linked_list/linked_list.hpp"


TEST_CASE("Double linked list test:"){
    SECTION("Function AddToTail() and Size(): "){
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        CHECK(list.Size() == 3);
    }

    SECTION("Function Insert() and Size(): "){
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        list.Insert(1, 22);
        CHECK(list.Size() == 4);
    }

    SECTION("Function GetAt():"){
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        CHECK(list.GetAt(1) == 6);
    }

    SECTION("operator [] :"){
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        CHECK(list[0] == 5);
    }

    SECTION("Function FindElement() :"){
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        CHECK(list.FindElement(7) == 2);
        CHECK(list.FindElement(5) == 0);
        CHECK(list.FindElement(6) == 1);
        CHECK(list.FindElement(25) == -1);
    }

    SECTION("Function RemoveLast() :"){
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        list.RemoveLast();
        CHECK(list.FindElement(7) == -1);
        CHECK(list.FindElement(6) == 1);
        CHECK(list.FindElement(5) == 0);
        CHECK(list.Size() == 2);

        list.RemoveLast();
        CHECK(list.FindElement(7) == -1);
        CHECK(list.FindElement(6) == -1);
        CHECK(list.FindElement(5) == 0);
        CHECK(list.Size() == 1);

        list.RemoveLast();
        CHECK(list.FindElement(7) == -1);
        CHECK(list.FindElement(6) == -1);
        CHECK(list.FindElement(5) == -1);
        CHECK(list.Size() == 0);
        CHECK(list.Empty() == true);

    }
    SECTION("Function RemoveElement() :") {
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        list.RemoveElement(6);
        CHECK(list.FindElement(6) == -1);
        CHECK(list.FindElement(7) == 1);
    }

    SECTION("Function RemoveByIndex() :") {
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        list.RemoveByIndex(0);
        CHECK(list.FindElement(5) == -1);
        CHECK(list.FindElement(6) == 0);
        CHECK(list.FindElement(7) == 1);

        list.RemoveByIndex(1);
        CHECK(list.FindElement(7) == -1);
        CHECK(list.Size() == 1);

        list.RemoveByIndex(0);
        CHECK(list.FindElement(6) == -1);
        CHECK(list.Size() == 0);
    }

    SECTION("Function Clear() :") {
        LinkedList<int> list;
        list.AddToTail(5);
        list.AddToTail(6);
        list.AddToTail(7);

        list.Clear();

        CHECK(list.Size() == 0);
    }

    SECTION("with string elements"){
        LinkedList<std::string> string_list;
        string_list.AddToTail("Hello");
    }
}