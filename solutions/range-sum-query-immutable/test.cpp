#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  NumArray *obj = new NumArray({-2, 0, 3, -5, 2, -1});
  REQUIRE(1 == obj->sumRange(0, 2));
  REQUIRE(-1 == obj->sumRange(2, 5));
  REQUIRE(-3 == obj->sumRange(0, 5));
}
