#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    REQUIRE(Solution::search(nums, 0));
    REQUIRE_FALSE(Solution::search(nums, 3));
  }
  {
    std::vector<int> nums{1, 0, 1, 1, 1};
    REQUIRE(Solution::search(nums, 0));
  }
}
