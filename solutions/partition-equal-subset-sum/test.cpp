#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 5, 11, 5};
    REQUIRE(Solution::canPartition(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 5};
    REQUIRE_FALSE(Solution::canPartition(nums));
  }
  {
    std::vector<int> nums{14, 9, 8, 4, 3, 2};
    REQUIRE(Solution::canPartition(nums));
  }
  {
    std::vector<int> nums{1, 2, 5};
    REQUIRE_FALSE(Solution::canPartition(nums));
  }
}
