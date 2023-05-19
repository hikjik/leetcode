#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    REQUIRE(6 == Solution::longestOnes(nums, k));
  }
  {
    int k = 3;
    std::vector<int> nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0,
                          1, 1, 0, 0, 0, 1, 1, 1, 1};
    REQUIRE(10 == Solution::longestOnes(nums, k));
  }
}
