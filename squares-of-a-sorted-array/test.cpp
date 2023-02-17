#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> values{-4, -1, 0, 3, 10};
    std::vector<int> expected{0, 1, 9, 16, 100};
    REQUIRE(expected == Solution::sortedSquares(values));
  }
  {
    std::vector<int> values{-7, -3, 2, 3, 11};
    std::vector<int> expected{4, 9, 9, 49, 121};
    REQUIRE(expected == Solution::sortedSquares(values));
  }
}
