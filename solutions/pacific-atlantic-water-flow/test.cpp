#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> heights{{1, 2, 2, 3, 5},
                                          {3, 2, 3, 4, 4},
                                          {2, 4, 5, 3, 1},
                                          {6, 7, 1, 4, 5},
                                          {5, 1, 1, 2, 4}};
    std::vector<std::vector<int>> cords{{0, 4}, {1, 3}, {1, 4}, {2, 2},
                                        {3, 0}, {3, 1}, {4, 0}};
    REQUIRE(cords == Solution::pacificAtlantic(heights));
  }
  {
    std::vector<std::vector<int>> heights{{1}};
    std::vector<std::vector<int>> cords{{0, 0}};
    REQUIRE(cords == Solution::pacificAtlantic(heights));
  }
}
