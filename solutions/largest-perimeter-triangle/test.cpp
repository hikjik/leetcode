#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 1, 2};
    REQUIRE(5 == Solution::largestPerimeter(nums));
  }
  {
    std::vector<int> nums{1, 2, 1, 10};
    REQUIRE(0 == Solution::largestPerimeter(nums));
  }
}
