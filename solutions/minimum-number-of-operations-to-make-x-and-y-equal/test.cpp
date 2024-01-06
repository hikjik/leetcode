#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int x;
    int y;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .x = 26,
          .y = 1,
          .expected = 3,
      },
      {
          .x = 54,
          .y = 2,
          .expected = 4,
      },
      {
          .x = 25,
          .y = 30,
          .expected = 5,
      },
  };

  for (const auto &[x, y, expected] : test_cases) {
    const auto actual = Solution::minimumOperationsToMakeEqual(x, y);
    REQUIRE(expected == actual);
  }
}
