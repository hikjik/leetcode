#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 2, 3};
    std::vector<int> expected{3};
    REQUIRE(expected == Solution::majorityElement(nums));
  }
  {
    std::vector<int> nums{1};
    std::vector<int> expected{1};
    REQUIRE(expected == Solution::majorityElement(nums));
  }
  {
    std::vector<int> nums{1, 2};
    std::vector<int> expected{1, 2};
    REQUIRE(expected == Solution::majorityElement(nums));
  }
}
