#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{4, 6, 5, 9, 3, 7};
    std::vector<int> l{0, 0, 2};
    std::vector<int> r{2, 3, 5};
    std::vector<bool> expected{true, false, true};
    REQUIRE(expected == Solution::checkArithmeticSubarrays(nums, l, r));
  }
  {
    std::vector<int> nums{-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
    std::vector<int> l{0, 1, 6, 4, 8, 7};
    std::vector<int> r{4, 4, 9, 7, 9, 10};
    std::vector<bool> expected{false, true, false, false, true, true};
    REQUIRE(expected == Solution::checkArithmeticSubarrays(nums, l, r));
  }
}
