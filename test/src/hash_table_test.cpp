#include "../lib/catch2/catch.hpp"
#include "../../include/hash_table/hash_table.hpp"

TEST_CASE("Hahs table with collision linked solution"){

    SECTION("GetHash"){
        HashTable_LC hash_table;
        int hash = hash_table.GetHash("Eduard");
        CHECK(hash <= 256);

        hash = hash_table.GetHash("Hakobyan");
        CHECK(hash <= 256);

        hash = hash_table.GetHash("Hello World");
        CHECK(hash <= 256);
    }


    SECTION("Add() && Size()"){
        HashTable_LC hash_table;
        std::string element;

        element = "eduard";
        hash_table.Add(element);
        CHECK(hash_table.Size() == 1);

        element = "Hakobyan";
        hash_table.Add(element);
        CHECK(hash_table.Size() == 2);

        element = "Hello World";
        hash_table.Add(element);
        CHECK(hash_table.Size() == 3);
    }

    SECTION("Remove() && Size() && Contains()"){
        HashTable_LC hash_table;
        hash_table.Add("Edo");
        hash_table.Add("Hakob");
        hash_table.Add("Smbo");
        hash_table.Add("Tiko");

        hash_table.Remove("Smbo");

        CHECK(hash_table.Size() == 3);
        CHECK(hash_table.Contains("Edo") == true);
        CHECK(hash_table.Contains("Hakob") == true);
        CHECK(hash_table.Contains("Smbo") == false);
    }
}