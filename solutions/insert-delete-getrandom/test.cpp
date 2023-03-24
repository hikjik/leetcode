#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  RandomizedSet set;
  REQUIRE(set.insert(1));
  REQUIRE_FALSE(set.remove(2));
  REQUIRE(set.insert(2));

  auto r = set.getRandom();
  REQUIRE(r >= 1);
  REQUIRE(r <= 2);

  REQUIRE(set.remove(1));
  REQUIRE_FALSE(set.insert(2));
  REQUIRE(2 == set.getRandom());
}
