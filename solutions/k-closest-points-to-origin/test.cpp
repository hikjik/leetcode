#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 1;
    std::vector<std::vector<int>> points{{1, 3}, {-2, 2}};
    std::vector<std::vector<int>> expected{{-2, 2}};
    auto actual = Solution::kClosest(points, k);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
  {
    int k = 2;
    std::vector<std::vector<int>> points{{3, 3}, {5, -1}, {-2, 4}};
    std::vector<std::vector<int>> expected{{-2, 4}, {3, 3}};
    auto actual = Solution::kClosest(points, k);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
  {
    int k = 1;
    std::vector<std::vector<int>> points{{2, 2}, {2, 2}, {2, 2}, {2, 2},
                                         {2, 2}, {2, 2}, {1, 1}};
    std::vector<std::vector<int>> expected{{1, 1}};
    auto actual = Solution::kClosest(points, k);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
}
