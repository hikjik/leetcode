#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> nums{1, 1, 1, 2, 2, 3};
    std::vector<int> expected{1, 2};
    auto actual = Solution::topKFrequent(nums, k);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
  {
    int k = 1;
    std::vector<int> nums{1};
    std::vector<int> expected{1};
    auto actual = Solution::topKFrequent(nums, k);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
}
