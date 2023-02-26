#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    REQUIRE(4 == Solution::search(nums, target));
  }
  {
    std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    REQUIRE(-1 == Solution::search(nums, target));
  }
  {
    std::vector<int> nums{1};
    int target = 0;
    REQUIRE(-1 == Solution::search(nums, target));
  }
}
