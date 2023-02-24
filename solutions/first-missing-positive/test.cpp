#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 0};
    REQUIRE(3 == Solution::firstMissingPositive(nums));
  }
  {
    std::vector<int> nums{3, 4, -1, 1};
    REQUIRE(2 == Solution::firstMissingPositive(nums));
  }
  {
    std::vector<int> nums{7, 8, 9, 11, 12};
    REQUIRE(1 == Solution::firstMissingPositive(nums));
  }
  {
    std::vector<int> nums{2, 2, 2};
    REQUIRE(1 == Solution::firstMissingPositive(nums));
  }
}
