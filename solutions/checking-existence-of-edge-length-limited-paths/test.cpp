#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3;
    std::vector<std::vector<int>> edgeList{
        {0, 1, 2}, {1, 2, 4}, {2, 0, 8}, {1, 0, 16}};
    std::vector<std::vector<int>> queries{{0, 1, 2}, {0, 2, 5}};
    std::vector<bool> expected{false, true};
    REQUIRE(expected ==
            Solution::distanceLimitedPathsExist(n, edgeList, queries));
  }
  {
    int n = 5;
    std::vector<std::vector<int>> edgeList{
        {0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}};
    std::vector<std::vector<int>> queries{{0, 4, 14}, {1, 4, 13}};
    std::vector<bool> expected{true, false};
    REQUIRE(expected ==
            Solution::distanceLimitedPathsExist(n, edgeList, queries));
  }
}
