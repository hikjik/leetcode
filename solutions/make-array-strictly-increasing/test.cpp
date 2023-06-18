#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<int> arr{1, 5, 3, 6, 7};
  REQUIRE(1 == Solution::makeArrayIncreasing(arr, {1, 3, 2, 4}));
  REQUIRE(2 == Solution::makeArrayIncreasing(arr, {4, 3, 1}));
  REQUIRE(-1 == Solution::makeArrayIncreasing(arr, {1, 6, 3, 3}));
}
