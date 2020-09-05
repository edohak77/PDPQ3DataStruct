#include "../lib/catch2/catch.hpp"
#include "../../include/hash_table/hash_table_OA.hpp"

TEST_CASE("Hahs table with collision open addressing solution"){

  SECTION("Add() && Contains() && Size() "){
      HashTable_AO hash_table;
      hash_table.Add("Eduard");
      hash_table.Add("Hello");

      CHECK(hash_table.Contains("Eduard") == true);

      CHECK(hash_table.Size() == 2);

      hash_table.Remove("Eduard");
      CHECK(hash_table.Contains("Eduard") == false);
      CHECK(hash_table.Size() == 1);

      CHECK(hash_table.Contains("Hello") == true);
      CHECK(hash_table.Contains("ello") == false);
      CHECK(hash_table.Size() == 1);
  }
}