#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> scores;
    std::vector<int> ages;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .scores{1, 3, 5, 10, 15},
          .ages{1, 2, 3, 4, 5},
          .expected = 34,
      },
      {
          .scores{4, 5, 6, 5},
          .ages{2, 1, 2, 1},
          .expected = 16,
      },
      {
          .scores{1, 2, 3, 5},
          .ages{8, 9, 10, 1},
          .expected = 6,
      },
  };

  SECTION("Memoization") {
    for (const auto &[scores, ages, expected] : test_cases) {
      const auto actual = memo::Solution::bestTeamScore(scores, ages);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[scores, ages, expected] : test_cases) {
      const auto actual = dp::Solution::bestTeamScore(scores, ages);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Segment Tree") {
    for (const auto &[scores, ages, expected] : test_cases) {
      const auto actual = st::Solution::bestTeamScore(scores, ages);
      REQUIRE(expected == actual);
    }
  }
}
