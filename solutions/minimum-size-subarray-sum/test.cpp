#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 3, 1, 2, 4, 3};
    int target = 7;
    REQUIRE(2 == Solution::minSubArrayLen(target, nums));
  }
  {
    std::vector<int> nums{1, 4, 4};
    int target = 4;
    REQUIRE(1 == Solution::minSubArrayLen(target, nums));
  }
  {
    std::vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
    int target = 11;
    REQUIRE(0 == Solution::minSubArrayLen(target, nums));
  }
}
