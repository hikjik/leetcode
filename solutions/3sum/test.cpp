#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> expected{{-1, -1, 2}, {-1, 0, 1}};
    REQUIRE(expected == Solution::threeSum(nums));
  }
  {
    std::vector<int> nums{0, 1, 1};
    std::vector<std::vector<int>> expected;
    REQUIRE(expected == Solution::threeSum(nums));
  }
  {
    std::vector<int> nums{0, 0, 0};
    std::vector<std::vector<int>> expected{{0, 0, 0}};
    REQUIRE(expected == Solution::threeSum(nums));
  }
}
