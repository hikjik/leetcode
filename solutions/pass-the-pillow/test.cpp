#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int time;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .time = 5,
          .expected = 2,
      },
      {
          .n = 3,
          .time = 2,
          .expected = 3,
      },
  };

  for (const auto &[n, time, expected] : test_cases) {
    const auto actual = Solution::passThePillow(n, time);
    REQUIRE(expected == actual);
  }
}
