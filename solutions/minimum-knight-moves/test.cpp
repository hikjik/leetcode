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
          .x = 2,
          .y = 1,
          .expected = 1,
      },
      {
          .x = 5,
          .y = 5,
          .expected = 4,
      },
  };

  for (const auto &[x, y, expected] : test_cases) {
    const auto actual = Solution::minKnightMoves(x, y);
    REQUIRE(expected == actual);
  }
}
