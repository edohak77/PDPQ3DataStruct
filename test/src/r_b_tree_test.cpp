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

        CHECK(tree.Contains(2) == true);
        CHECK(tree.Contains(16) == true);
        CHECK(tree.Contains(15) == true);
        CHECK(tree.Contains(5) == true);

        tree.Remove(2);
        tree.Remove(5);
        CHECK(tree.Contains(2) == false);
        CHECK(tree.Contains(16) == true);
        CHECK(tree.Contains(15) == true);
        CHECK(tree.Contains(5) == false);
    }
}