#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto my_hash_set = MyHashSet();

  my_hash_set.add(1);
  my_hash_set.add(2);
  REQUIRE(true == my_hash_set.contains(1));
  REQUIRE(false == my_hash_set.contains(3));
  my_hash_set.add(2);
  REQUIRE(true == my_hash_set.contains(2));
  my_hash_set.remove(2);
  REQUIRE(false == my_hash_set.contains(2));
}
