#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto my_hash_map = MyHashMap();

  my_hash_map.put(1, 1);
  my_hash_map.put(2, 2);
  REQUIRE(1 == my_hash_map.get(1));
  REQUIRE(-1 == my_hash_map.get(3));
  my_hash_map.put(2, 1);
  REQUIRE(1 == my_hash_map.get(2));
  my_hash_map.remove(2);
  REQUIRE(-1 == my_hash_map.get(2));
}
