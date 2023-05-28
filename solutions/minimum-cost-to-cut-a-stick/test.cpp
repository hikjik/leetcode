#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 7;
    std::vector<int> cuts{1, 3, 4, 5};
    REQUIRE(16 == Solution().minCost(n, cuts));
  }
  {
    int n = 9;
    std::vector<int> cuts{5, 6, 1, 4, 2};
    REQUIRE(22 == Solution().minCost(n, cuts));
  }
}