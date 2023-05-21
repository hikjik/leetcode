#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int size = 5;
    std::vector<int> nums{1, 1, 1, 2, 2, 3};
    REQUIRE(size == Solution::removeDuplicates(nums));

    nums.erase(nums.begin() + size, nums.end());
    std::vector<int> expected{1, 1, 2, 2, 3};
    REQUIRE(expected == nums);
  }
  {
    int size = 7;
    std::vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
    REQUIRE(size == Solution::removeDuplicates(nums));

    nums.erase(nums.begin() + size, nums.end());
    std::vector<int> expected{0, 0, 1, 1, 2, 3, 3};
    REQUIRE(expected == nums);
  }
}
