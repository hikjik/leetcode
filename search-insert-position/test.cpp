#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 3, 5, 6};
    int target = 5;
    REQUIRE(2 == Solution::searchInsert(nums, target));
  }
  {
    std::vector<int> nums{1, 3, 5, 6};
    int target = 2;
    REQUIRE(1 == Solution::searchInsert(nums, target));
  }
  {
    std::vector<int> nums{1, 3, 5, 6};
    int target = 7;
    REQUIRE(4 == Solution::searchInsert(nums, target));
  }
}
