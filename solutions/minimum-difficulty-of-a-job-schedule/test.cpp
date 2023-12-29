#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> jobDifficulty;
    int d;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .jobDifficulty{6, 5, 4, 3, 2, 1},
          .d = 2,
          .expected = 7,
      },
      {
          .jobDifficulty{9, 9, 9},
          .d = 4,
          .expected = -1,
      },
      {
          .jobDifficulty{1, 1, 1},
          .d = 3,
          .expected = 3,
      },
      {
          .jobDifficulty{186, 398, 479, 206, 885, 423, 805, 112, 925, 656, 16,
                         932, 740, 292, 671, 360},
          .d = 4,
          .expected = 1803,
      },
  };

  SECTION("Memoization") {
    for (const auto &[jobDifficulty, d, expected] : test_cases) {
      const auto actual = memo::Solution::minDifficulty(jobDifficulty, d);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[jobDifficulty, d, expected] : test_cases) {
      const auto actual = dp::Solution::minDifficulty(jobDifficulty, d);
      REQUIRE(expected == actual);
    }
  }
}
