#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 7,
          .expected = false,
      },
      {
          .n = 1,
          .expected = true,
      },
      {
          .n = 2,
          .expected = false,
      },
      {
          .n = 4,
          .expected = true,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::winnerSquareGame(n);
    REQUIRE(expected == actual);
  }
}
