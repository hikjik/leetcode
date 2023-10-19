#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> dominoes;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .dominoes{{1, 2}, {2, 1}, {3, 4}, {5, 6}},
          .expected = 1,
      },
      {
          .dominoes{{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}},
          .expected = 3,
      },
  };

  for (const auto &[dominoes, expected] : test_cases) {
    const auto actual = Solution::numEquivDominoPairs(dominoes);
    REQUIRE(expected == actual);
  }
}
