#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> timeSeries;
    int duration;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .timeSeries{1, 4},
          .duration = 2,
          .expected = 4,
      },
      {
          .timeSeries{1, 2},
          .duration = 2,
          .expected = 3,
      },
  };

  for (const auto &[timeSeries, duration, expected] : test_cases) {
    const auto actual = Solution::findPoisonedDuration(timeSeries, duration);
    REQUIRE(expected == actual);
  }
}
