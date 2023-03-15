#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int target = 8;
    std::vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    std::vector<std::vector<int>> combinations{
        {1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
    auto actual = Solution::combinationSum2(candidates, target);
    std::sort(actual.begin(), actual.end());
    REQUIRE(combinations == actual);
  }
  {
    int target = 5;
    std::vector<int> candidates{2, 5, 2, 1, 2};
    std::vector<std::vector<int>> combinations{{1, 2, 2}, {5}};
    auto actual = Solution::combinationSum2(candidates, target);
    std::sort(actual.begin(), actual.end());
    REQUIRE(combinations == actual);
  }
}
