#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> candidates;
    int target;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .candidates{2, 3, 6, 7},
          .target = 7,
          .expected{{2, 2, 3}, {7}},
      },
      {
          .candidates{2, 3, 5},
          .target = 8,
          .expected{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}},
      },
      {
          .candidates{2},
          .target = 1,
          .expected{},
      },
  };

  for (const auto &[candidates, target, expected] : test_cases) {
    const auto actual = Solution::combinationSum(candidates, target);
    REQUIRE(expected == actual);
  }
}
