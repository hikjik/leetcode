#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  MyHashSet myHashSet;
  myHashSet.add(1);
  myHashSet.add(2);
  REQUIRE(myHashSet.contains(1));
  REQUIRE_FALSE(myHashSet.contains(3));
  myHashSet.add(2);
  REQUIRE(myHashSet.contains(2));
  myHashSet.remove(2);
  REQUIRE_FALSE(myHashSet.contains(2));
}
