#include "../lib/catch2/catch.hpp"
#include "../../include/my_vector/my_vector.hpp"

TEST_CASE("My vector functionality") {

    SECTION("Function GetAT():") {
        MyVector<double> vec;
        vec.Add(0.5);
        vec.Add(1.5);
        vec.Add(2.5);
        CHECK(vec.GetAt(0) == 0.5);
        CHECK(vec.GetAt(1) == 1.5);
        CHECK(vec.GetAt(2) == 2.5);
    }

    SECTION("Function GetAt() assertion:"){
        MyVector<double> vec;
        vec.Add(-1);
        CHECK_THROWS(vec.GetAt(-1));
    }

    SECTION("Function Delete last: "){
        MyVector<double> vec;
        vec.Add(0.5);
        vec.Add(1.5);
        vec.Add(2.5);

        vec.DeleteLast();
        vec.DeleteLast();
        vec.DeleteLast();

        CHECK(vec.Size() == 0);
    }

    SECTION("Function Delete las as throw:"){
        MyVector<double> vec;
        vec.Add(0.5);
        vec.Add(1.5);
        vec.Add(2.5);

        vec.DeleteLast();
        vec.DeleteLast();
        vec.DeleteLast();

        CHECK_THROWS(vec.DeleteLast());
    }

    SECTION("Function Clean():"){
        MyVector<double> vec;
        vec.Add(0.5);
        vec.Add(1.5);
        vec.Add(2.5);

        vec.Clear();

        CHECK(vec.Size() == 0);
    }

    SECTION("Function Empty():"){
        MyVector<double> vec;
        vec.Add(0.5);
        vec.Add(1.5);
        vec.Add(2.5);

        vec.Clear();

        CHECK(vec.Empty() == true);
    }

    SECTION("Function Empty() -> for <FALSE>:"){
        MyVector<double> vec;
        vec.Add(0.5);
        vec.Add(1.5);
        vec.Add(2.5);

        CHECK_FALSE(vec.Empty());
    }

}
