#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> values;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .values{8, 1, 5, 2, 6},
          .expected = 11,
      },
      {
          .values{1, 2},
          .expected = 2,
      },
  };

  for (const auto &[values, expected] : test_cases) {
    const auto actual = Solution::maxScoreSightseeingPair(values);
    REQUIRE(expected == actual);
  }
}
