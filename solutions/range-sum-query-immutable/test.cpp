#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<int> nums{-2, 0, 3, -5, 2, -1};
  auto num_array = NumArray(nums);

  REQUIRE(1 == num_array.sumRange(0, 2));
  REQUIRE(-1 == num_array.sumRange(2, 5));
  REQUIRE(-3 == num_array.sumRange(0, 5));
}
