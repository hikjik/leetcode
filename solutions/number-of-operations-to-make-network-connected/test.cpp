#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 4;
    std::vector<std::vector<int>> connections{{0, 1}, {0, 2}, {1, 2}};
    REQUIRE(1 == Solution::makeConnected(n, connections));
  }
  {
    int n = 6;
    std::vector<std::vector<int>> connections{
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    REQUIRE(2 == Solution::makeConnected(n, connections));
  }
  {
    int n = 6;
    std::vector<std::vector<int>> connections{{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    REQUIRE(-1 == Solution::makeConnected(n, connections));
  }
}
