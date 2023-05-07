#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int target = 0;
    std::vector<std::vector<int>> mat{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    REQUIRE(4 == Solution::numSubmatrixSumTarget(mat, target));
  }
  {
    int target = 0;
    std::vector<std::vector<int>> mat{{1, -1}, {-1, 1}};
    REQUIRE(5 == Solution::numSubmatrixSumTarget(mat, target));
  }
  {
    int target = 0;
    std::vector<std::vector<int>> mat{{904}};
    REQUIRE(0 == Solution::numSubmatrixSumTarget(mat, target));
  }
}
