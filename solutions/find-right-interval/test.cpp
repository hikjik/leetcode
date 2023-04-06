#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> intervals{{1, 2}};
    std::vector<int> expected{-1};
    REQUIRE(expected == Solution::findRightInterval(intervals));
  }
  {
    std::vector<std::vector<int>> intervals{{3, 4}, {2, 3}, {1, 2}};
    std::vector<int> expected{-1, 0, 1};
    REQUIRE(expected == Solution::findRightInterval(intervals));
  }
  {
    std::vector<std::vector<int>> intervals{{1, 4}, {2, 3}, {3, 4}};
    std::vector<int> expected{-1, 2, -1};
    REQUIRE(expected == Solution::findRightInterval(intervals));
  }
}
