#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 3, 5, 2, 7, 5};
    int min = 1, max = 5;
    REQUIRE(2 == Solution::countSubarrays(nums, min, max));
  }
  {
    std::vector<int> nums{1, 1, 1, 1};
    int min = 1, max = 1;
    REQUIRE(10 == Solution::countSubarrays(nums, min, max));
  }
  {
    std::vector<int> nums{1, 4, 9, 9, 8, 9, 1, 9, 3, 9, 1, 2, 7, 5, 6};
    int min = 1, max = 9;
    REQUIRE(81 == Solution::countSubarrays(nums, min, max));
  }
}
