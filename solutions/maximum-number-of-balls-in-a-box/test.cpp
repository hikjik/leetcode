#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int lowLimit;
    int highLimit;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .lowLimit = 1,
          .highLimit = 10,
          .expected = 2,
      },
      {
          .lowLimit = 5,
          .highLimit = 15,
          .expected = 2,
      },
      {
          .lowLimit = 19,
          .highLimit = 28,
          .expected = 2,
      },
  };

  for (const auto &[lowLimit, highLimit, expected] : test_cases) {
    const auto actual = Solution::countBalls(lowLimit, highLimit);
    REQUIRE(expected == actual);
  }
}
