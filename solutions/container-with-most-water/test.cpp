#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    REQUIRE(49 == Solution::maxArea(height));
  }
  {
    std::vector<int> height{1, 1};
    REQUIRE(1 == Solution::maxArea(height));
  }
}
