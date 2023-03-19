#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 1};
    std::vector<int> expected{2, -1, 2};
    REQUIRE(expected == Solution::nextGreaterElements(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 4, 3};
    std::vector<int> expected{2, 3, 4, -1, 4};
    REQUIRE(expected == Solution::nextGreaterElements(nums));
  }
}
