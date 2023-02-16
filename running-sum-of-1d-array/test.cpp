#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 4};
    std::vector<int> expected{1, 3, 6, 10};
    REQUIRE(expected == Solution::runningSum(nums));
  }
  {
    std::vector<int> nums{1, 1, 1, 1, 1};
    std::vector<int> expected{1, 2, 3, 4, 5};
    REQUIRE(expected == Solution::runningSum(nums));
  }
  {
    std::vector<int> nums{3, 1, 2, 10, 1};
    std::vector<int> expected{3, 4, 6, 16, 17};
    REQUIRE(expected == Solution::runningSum(nums));
  }
}
