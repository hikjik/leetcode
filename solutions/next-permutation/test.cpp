#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3};
    Solution::nextPermutation(nums);
    std::vector<int> expected{1, 3, 2};
    REQUIRE(expected == nums);
  }
  {
    std::vector<int> nums{3, 2, 1};
    Solution::nextPermutation(nums);
    std::vector<int> expected{1, 2, 3};
    REQUIRE(expected == nums);
  }
  {
    std::vector<int> nums{1, 1, 5};
    Solution::nextPermutation(nums);
    std::vector<int> expected{1, 5, 1};
    REQUIRE(expected == nums);
  }
}
