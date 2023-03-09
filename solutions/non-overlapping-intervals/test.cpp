#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    REQUIRE(1 == Solution::eraseOverlapIntervals(intervals));
  }
  {
    std::vector<std::vector<int>> intervals{{1, 2}, {1, 2}, {1, 2}};
    REQUIRE(2 == Solution::eraseOverlapIntervals(intervals));
  }
  {
    std::vector<std::vector<int>> intervals{{1, 2}, {2, 3}};
    REQUIRE(0 == Solution::eraseOverlapIntervals(intervals));
  }
}
