#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto smallest_infinite_set = SmallestInfiniteSet();

  smallest_infinite_set.addBack(2);
  REQUIRE(1 == smallest_infinite_set.popSmallest());
  REQUIRE(2 == smallest_infinite_set.popSmallest());
  REQUIRE(3 == smallest_infinite_set.popSmallest());
  smallest_infinite_set.addBack(1);
  REQUIRE(1 == smallest_infinite_set.popSmallest());
  REQUIRE(4 == smallest_infinite_set.popSmallest());
  REQUIRE(5 == smallest_infinite_set.popSmallest());
}
