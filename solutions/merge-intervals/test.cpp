#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> expected{{1, 6}, {8, 10}, {15, 18}};
    REQUIRE(expected == Solution::merge(intervals));
  }
  {
    std::vector<std::vector<int>> intervals{{1, 4}, {4, 5}};
    std::vector<std::vector<int>> expected{{1, 5}};
    REQUIRE(expected == Solution::merge(intervals));
  }
}
