#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    std::vector<std::vector<int>> expected{{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    REQUIRE(expected == Solution::floodFill(image, sr, sc, color));
  }
  {
    std::vector<std::vector<int>> image{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int sr = 0;
    int sc = 0;
    int color = 0;
    std::vector<std::vector<int>> expected{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    REQUIRE(expected == Solution::floodFill(image, sr, sc, color));
  }
}
