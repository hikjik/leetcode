#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  SmallestInfiniteSet infinite_set;
  infinite_set.addBack(2);
  REQUIRE(1 == infinite_set.popSmallest());
  REQUIRE(2 == infinite_set.popSmallest());
  REQUIRE(3 == infinite_set.popSmallest());
  infinite_set.addBack(1);
  REQUIRE(1 == infinite_set.popSmallest());
  REQUIRE(4 == infinite_set.popSmallest());
  REQUIRE(5 == infinite_set.popSmallest());
}
