#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 9;
    REQUIRE(4 == Solution::search(nums, target));
  }
  {
    std::vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 2;
    REQUIRE(-1 == Solution::search(nums, target));
  }
}
