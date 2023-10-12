#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int a;
    int b;
    int c;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .a = 2,
          .b = 3,
          .c = 5,
          .expected = 4,
      },
      {
          .n = 4,
          .a = 2,
          .b = 3,
          .c = 4,
          .expected = 6,
      },
      {
          .n = 5,
          .a = 2,
          .b = 11,
          .c = 13,
          .expected = 10,
      },
  };

  for (const auto &[n, a, b, c, expected] : test_cases) {
    const auto actual = Solution::nthUglyNumber(n, a, b, c);
    REQUIRE(expected == actual);
  }
}
