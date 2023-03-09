#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto map = new MyHashMap();
  map->put(1, 1);
  map->put(2, 2);
  REQUIRE(1 == map->get(1));
  REQUIRE(-1 == map->get(3));
  map->put(2, 1);
  REQUIRE(1 == map->get(2));
  map->remove(2);
  REQUIRE(-1 == map->get(2));
}
