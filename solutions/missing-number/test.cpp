#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 0, 1};
    REQUIRE(2 == Solution::missingNumber(nums));
  }
  {
    std::vector<int> nums{0, 1};
    REQUIRE(2 == Solution::missingNumber(nums));
  }
  {
    std::vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
    REQUIRE(8 == Solution::missingNumber(nums));
  }
}
