#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int target = 7;
    std::vector<int> candidates{2, 3, 6, 7};
    std::vector<std::vector<int>> combinations{{2, 2, 3}, {7}};
    REQUIRE(combinations == Solution::combinationSum(candidates, target));
  }
  {
    int target = 8;
    std::vector<int> candidates{2, 3, 5};
    std::vector<std::vector<int>> combinations{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    REQUIRE(combinations == Solution::combinationSum(candidates, target));
  }
  {
    int target = 1;
    std::vector<int> candidates{2};
    std::vector<std::vector<int>> combinations;
    REQUIRE(combinations == Solution::combinationSum(candidates, target));
  }
}
