#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int x;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .x = 4,
          .expected = 2,
      },
      {
          .x = 8,
          .expected = 2,
      },
      {
          .x = 0,
          .expected = 0,
      },
  };

  for (const auto &[x, expected] : test_cases) {
    const auto actual = Solution::mySqrt(x);
    REQUIRE(expected == actual);
  }
}
