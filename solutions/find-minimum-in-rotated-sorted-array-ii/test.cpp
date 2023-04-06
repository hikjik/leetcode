#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 3, 5};
    REQUIRE(1 == Solution::findMin(nums));
  }
  {
    std::vector<int> nums{2, 2, 2, 0, 1};
    REQUIRE(0 == Solution::findMin(nums));
  }
  {
    std::vector<int> nums{1, 3, 3};
    REQUIRE(1 == Solution::findMin(nums));
  }
}
