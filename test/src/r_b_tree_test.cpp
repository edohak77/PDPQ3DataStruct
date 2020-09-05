#include "../lib/catch2/catch.hpp"
#include "../../include/b_tree/r_b_tree.hpp"

TEST_CASE("RED BLACK Tree:"){
    SECTION("Add() functionality"){
        RBTree tree;

        tree.Add(10);
        tree.Add(5);
        tree.Add(15);
        tree.Add(3);
        tree.Add(16);
        tree.Add(2);
    }
}