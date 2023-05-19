#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 4;
    std::vector<int> nums{1, 12, -5, -6, 50, 3};
    double expected = 12.750000;
    REQUIRE(expected == Solution::findMaxAverage(nums, k));
  }
  {
    int k = 1;
    std::vector<int> nums{5};
    double expected = 5.00000;
    REQUIRE(expected == Solution::findMaxAverage(nums, k));
  }
  {
    int k = 1;
    std::vector<int> nums{-1};
    double expected = -1.00000;
    REQUIRE(expected == Solution::findMaxAverage(nums, k));
  }
}
