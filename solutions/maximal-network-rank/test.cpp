#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 4;
    std::vector<std::vector<int>> roads{{0, 1}, {0, 3}, {1, 2}, {1, 3}};
    REQUIRE(4 == Solution::maximalNetworkRank(n, roads));
  }
  {
    int n = 5;
    std::vector<std::vector<int>> roads{{0, 1}, {0, 3}, {1, 2},
                                        {1, 3}, {2, 3}, {2, 4}};
    REQUIRE(5 == Solution::maximalNetworkRank(n, roads));
  }
  {
    int n = 8;
    std::vector<std::vector<int>> roads{{0, 1}, {1, 2}, {2, 3},
                                        {2, 4}, {5, 6}, {5, 7}};
    REQUIRE(5 == Solution::maximalNetworkRank(n, roads));
  }
}
