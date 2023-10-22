#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> logs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .logs{{1993, 1999}, {2000, 2010}},
          .expected = 1993,
      },
      {
          .logs{{1950, 1961}, {1960, 1971}, {1970, 1981}},
          .expected = 1960,
      },
  };

  for (const auto &[logs, expected] : test_cases) {
    const auto actual = Solution::maximumPopulation(logs);
    REQUIRE(expected == actual);
  }
}
