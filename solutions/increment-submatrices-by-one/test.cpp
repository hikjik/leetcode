#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3;
    std::vector<std::vector<int>> queries{{1, 1, 2, 2}, {0, 0, 1, 1}};
    std::vector<std::vector<int>> expected{{1, 1, 0}, {1, 2, 1}, {0, 1, 1}};
    REQUIRE(expected == Solution::rangeAddQueries(n, queries));
  }
  {
    int n = 2;
    std::vector<std::vector<int>> queries{{0, 0, 1, 1}};
    std::vector<std::vector<int>> expected{{1, 1}, {1, 1}};
    REQUIRE(expected == Solution::rangeAddQueries(n, queries));
  }
}
