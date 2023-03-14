#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 1, 2};
    std::vector<std::vector<int>> permutations{{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    REQUIRE(permutations == Solution::permuteUnique(nums));
  }
  {
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> permutations{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                               {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    REQUIRE(permutations == Solution::permuteUnique(nums));
  }
  {
    std::vector<int> nums{0, 1};
    std::vector<std::vector<int>> permutations{{0, 1}, {1, 0}};
    REQUIRE(permutations == Solution::permuteUnique(nums));
  }
  {
    std::vector<int> nums{1};
    std::vector<std::vector<int>> permutations{{1}};
    REQUIRE(permutations == Solution::permuteUnique(nums));
  }
}
