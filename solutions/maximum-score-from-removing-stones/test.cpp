#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int a;
    int b;
    int c;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .a = 2,
          .b = 4,
          .c = 6,
          .expected = 6,
      },
      {
          .a = 4,
          .b = 4,
          .c = 6,
          .expected = 7,
      },
      {
          .a = 1,
          .b = 8,
          .c = 8,
          .expected = 8,
      },
  };

  for (const auto &[a, b, c, expected] : test_cases) {
    const auto actual = Solution::maximumScore(a, b, c);
    REQUIRE(expected == actual);
  }
}
