#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3;
    std::vector<int> nums{1, 2, 3, 1};
    REQUIRE(Solution::containsNearbyDuplicate(nums, k));
  }
  {
    int k = 1;
    std::vector<int> nums{1, 0, 1, 1};
    REQUIRE(Solution::containsNearbyDuplicate(nums, k));
  }
  {
    int k = 2;
    std::vector<int> nums{1, 2, 3, 1, 2, 3};
    REQUIRE_FALSE(Solution::containsNearbyDuplicate(nums, k));
  }
}
