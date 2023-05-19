#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3, n = 7;
    std::vector<std::vector<int>> expected{{1, 2, 4}};
    REQUIRE(expected == Solution::combinationSum3(k, n));
  }
  {
    int k = 3, n = 9;
    std::vector<std::vector<int>> expected{{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
    REQUIRE(expected == Solution::combinationSum3(k, n));
  }
  {
    int k = 4, n = 1;
    std::vector<std::vector<int>> expected;
    REQUIRE(expected == Solution::combinationSum3(k, n));
  }
}
