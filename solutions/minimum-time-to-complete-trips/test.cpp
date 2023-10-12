#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> time;
    int totalTrips;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .time{1, 2, 3},
          .totalTrips = 5,
          .expected = 3,
      },
      {
          .time{2},
          .totalTrips = 1,
          .expected = 2,
      },
  };

  for (const auto &[time, totalTrips, expected] : test_cases) {
    const auto actual = Solution::minimumTime(time, totalTrips);
    REQUIRE(expected == actual);
  }
}
