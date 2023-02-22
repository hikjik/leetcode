#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1 - 2, 3, -2};
    REQUIRE(3 == Solution::maxSubarraySumCircular(nums));
  }
  {
    std::vector<int> nums{5, -3, 5};
    REQUIRE(10 == Solution::maxSubarraySumCircular(nums));
  }
  {
    std::vector<int> nums{-3, -2, -3};
    REQUIRE(-2 == Solution::maxSubarraySumCircular(nums));
  }
  {
    std::vector<int> nums{1};
    REQUIRE(1 == Solution::maxSubarraySumCircular(nums));
  }
}
