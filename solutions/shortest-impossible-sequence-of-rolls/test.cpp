#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> rolls;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rolls{4, 2, 1, 2, 3, 3, 2, 4, 1},
          .k = 4,
          .expected = 3,
      },
      {
          .rolls{1, 1, 2, 2},
          .k = 2,
          .expected = 2,
      },
      {
          .rolls{1, 1, 3, 2, 2, 2, 3, 3},
          .k = 4,
          .expected = 1,
      },
  };

  for (const auto &[rolls, k, expected] : test_cases) {
    const auto actual = Solution::shortestSequence(rolls, k);
    REQUIRE(expected == actual);
  }
}
