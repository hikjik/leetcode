#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> dist;
    double hour;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .dist{1, 3, 2},
          .hour = 6,
          .expected = 1,
      },
      {
          .dist{1, 3, 2},
          .hour = 2.7,
          .expected = 3,
      },
      {
          .dist{1, 3, 2},
          .hour = 1.9,
          .expected = -1,
      },
  };

  for (const auto &[dist, hour, expected] : test_cases) {
    const auto actual = Solution::minSpeedOnTime(dist, hour);
    REQUIRE(expected == actual);
  }
}
