#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> heights{2, 1, 5, 6, 2, 3};
    REQUIRE(10 == Solution::largestRectangleArea(heights));
  }
  {
    std::vector<int> heights{2, 4};
    REQUIRE(4 == Solution::largestRectangleArea(heights));
  }
}
