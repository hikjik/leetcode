#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 1;
    std::vector<std::vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> sum{{12, 21, 16}, {27, 45, 33}, {24, 39, 28}};
    REQUIRE(sum == Solution::matrixBlockSum(mat, k));
  }
  {
    int k = 2;
    std::vector<std::vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> sum{{45, 45, 45}, {45, 45, 45}, {45, 45, 45}};
    REQUIRE(sum == Solution::matrixBlockSum(mat, k));
  }
}
