#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{100, 4, 200, 1, 3, 2};
    REQUIRE(4 == Solution::longestConsecutive(nums));
  }
  {
    std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    REQUIRE(9 == Solution::longestConsecutive(nums));
  }
  {
    std::vector<int> nums;
    REQUIRE(0 == Solution::longestConsecutive(nums));
  }
}
