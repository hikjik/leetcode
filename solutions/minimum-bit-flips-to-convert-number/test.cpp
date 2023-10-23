#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int start;
    int goal;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .start = 10,
          .goal = 7,
          .expected = 3,
      },
      {
          .start = 3,
          .goal = 4,
          .expected = 3,
      },
  };

  for (const auto &[start, goal, expected] : test_cases) {
    const auto actual = Solution::minBitFlips(start, goal);
    REQUIRE(expected == actual);
  }
}
