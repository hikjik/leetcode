#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 4;
    std::vector<std::vector<int>> dislikes{{1, 2}, {1, 3}, {2, 4}};
    REQUIRE(Solution::possibleBipartition(n, dislikes));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> dislikes{{1, 2}, {1, 3}, {2, 3}};
    REQUIRE_FALSE(Solution::possibleBipartition(n, dislikes));
  }
  {
    int n = 10;
    std::vector<std::vector<int>> dislikes{{1, 2}, {3, 4}, {5, 6},
                                           {6, 7}, {8, 9}, {7, 8}};
    REQUIRE(Solution::possibleBipartition(n, dislikes));
  }
}
