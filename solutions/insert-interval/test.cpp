#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> intervals{{1, 3}, {6, 9}};
    std::vector<int> new_interval{2, 5};
    std::vector<std::vector<int>> expected{{1, 5}, {6, 9}};
    REQUIRE(expected == Solution::insert(intervals, new_interval));
  }
  {
    std::vector<std::vector<int>> intervals{
        {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<int> new_interval{4, 8};
    std::vector<std::vector<int>> expected{{1, 2}, {3, 10}, {12, 16}};
    REQUIRE(expected == Solution::insert(intervals, new_interval));
  }
  {
    std::vector<std::vector<int>> intervals;
    std::vector<int> new_interval{5, 7};
    std::vector<std::vector<int>> expected{{5, 7}};
    REQUIRE(expected == Solution::insert(intervals, new_interval));
  }
}
