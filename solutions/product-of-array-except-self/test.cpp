#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 4};
    std::vector<int> expected{24, 12, 8, 6};
    REQUIRE(expected == Solution::productExceptSelf(nums));
  }
  {
    std::vector<int> nums{-1, 1, 0, -3, 3};
    std::vector<int> expected{0, 0, 9, 0, 0};
    REQUIRE(expected == Solution::productExceptSelf(nums));
  }
  {
    std::vector<int> nums{-1, 1, 0, -3, 0};
    std::vector<int> expected{0, 0, 0, 0, 0};
    REQUIRE(expected == Solution::productExceptSelf(nums));
  }
}
