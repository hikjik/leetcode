#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int capacity = 2;
  auto cache = LRUCache(capacity);

  cache.put(1, 1);
  cache.put(2, 2);
  REQUIRE(1 == cache.get(1));
  cache.put(3, 3);
  REQUIRE(-1 == cache.get(2));
  cache.put(4, 4);
  REQUIRE(-1 == cache.get(1));
  REQUIRE(3 == cache.get(3));
  REQUIRE(4 == cache.get(4));
}
