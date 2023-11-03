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
          .candidates{10, 1, 2, 7, 6, 1, 5},
          .target = 8,
          .expected{{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}},
      },
      {
          .candidates{2, 5, 2, 1, 2},
          .target = 5,
          .expected{{1, 2, 2}, {5}},
      },
  };

  for (const auto &[candidates, target, expected] : test_cases) {
    const auto actual = Solution::combinationSum2(candidates, target);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
