#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3;
    std::vector<int> nums{7, 4, 3, 9, 1, 8, 5, 2, 6};
    std::vector<int> expected{-1, -1, -1, 5, 4, 4, -1, -1, -1};
    REQUIRE(expected == Solution::getAverages(nums, k));
  }
  {
    int k = 0;
    std::vector<int> nums{100000};
    std::vector<int> expected{100000};
    REQUIRE(expected == Solution::getAverages(nums, k));
  }
  {
    int k = 100000;
    std::vector<int> nums{8};
    std::vector<int> expected{-1};
    REQUIRE(expected == Solution::getAverages(nums, k));
  }
}