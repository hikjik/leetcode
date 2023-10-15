#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int steps;
    int arrLen;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .steps = 3,
          .arrLen = 2,
          .expected = 4,
      },
      {
          .steps = 2,
          .arrLen = 4,
          .expected = 2,
      },
      {
          .steps = 4,
          .arrLen = 2,
          .expected = 8,
      },
  };

  for (const auto &[steps, arrLen, expected] : test_cases) {
    const auto actual = Solution::numWays(steps, arrLen);
    REQUIRE(expected == actual);
  }
}
