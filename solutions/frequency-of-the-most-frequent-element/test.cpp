#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 5;
    std::vector<int> nums{1, 2, 4};
    REQUIRE(3 == Solution::maxFrequency(nums, k));
  }
  {
    int k = 5;
    std::vector<int> nums{1, 4, 8, 13};
    REQUIRE(2 == Solution::maxFrequency(nums, k));
  }
  {
    int k = 2;
    std::vector<int> nums{3, 9, 6};
    REQUIRE(1 == Solution::maxFrequency(nums, k));
  }
}
