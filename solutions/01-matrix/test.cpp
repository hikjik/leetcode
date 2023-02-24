#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> mat{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    std::vector<std::vector<int>> expected{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    REQUIRE(expected == Solution::updateMatrix(mat));
  }
  {
    std::vector<std::vector<int>> mat{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    std::vector<std::vector<int>> expected{{0, 0, 0}, {0, 1, 0}, {1, 2, 1}};
    REQUIRE(expected == Solution::updateMatrix(mat));
  }
}
