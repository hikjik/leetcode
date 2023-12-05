#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 8,
          .expected = 3,
      },
      {
          .n = 7,
          .expected = 4,
      },
      {
          .n = 4,
          .expected = 2,
      },
      {
          .n = INT_MAX,
          .expected = 32,
      },
      {
          .n = 3,
          .expected = 2,
      },
      {
          .n = 100000000,
          .expected = 31,
      },
  };

  SECTION("Memoization") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = memo::Solution::integerReplacement(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Bit Manipulation") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = bits::Solution::integerReplacement(n);
      REQUIRE(expected == actual);
    }
  }
}
