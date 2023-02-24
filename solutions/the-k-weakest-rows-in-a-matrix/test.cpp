#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> mat{{1, 1, 0, 0, 0},
                                      {1, 1, 1, 1, 0},
                                      {1, 0, 0, 0, 0},
                                      {1, 1, 0, 0, 0},
                                      {1, 1, 1, 1, 1}};
    int k = 3;
    std::vector<int> expected{2, 0, 3};
    REQUIRE(expected == Solution::kWeakestRows(mat, k));
  }
  {
    std::vector<std::vector<int>> mat{
        {1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};
    int k = 2;
    std::vector<int> expected{0, 2};
    REQUIRE(expected == Solution::kWeakestRows(mat, k));
  }
}
