#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> heights{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    REQUIRE(6 == Solution::trap(heights));
  }
  {
    std::vector<int> heights{4, 2, 0, 3, 2, 5};
    REQUIRE(9 == Solution::trap(heights));
  }
  {
    std::vector<int> heights;
    REQUIRE(0 == Solution::trap(heights));
  }
}
