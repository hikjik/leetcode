#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 4, 5, 1, 2};
    REQUIRE(1 == Solution::findMin(nums));
  }
  {
    std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    REQUIRE(0 == Solution::findMin(nums));
  }
  {
    std::vector<int> nums{11, 13, 15, 17};
    REQUIRE(11 == Solution::findMin(nums));
  }
  {
    std::vector<int> nums{1};
    REQUIRE(1 == Solution::findMin(nums));
  }
}
