#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 1, 0, 1};
    REQUIRE(3 == Solution::longestSubarray(nums));
  }
  {
    std::vector<int> nums{0, 1, 1, 1, 0, 1, 1, 0, 1};
    REQUIRE(5 == Solution::longestSubarray(nums));
  }
  {
    std::vector<int> nums{1, 1, 1};
    REQUIRE(2 == Solution::longestSubarray(nums));
  }
}
