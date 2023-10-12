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
          .b = 6,
          .c = 5,
          .expected = 3,
      },
      {
          .a = 4,
          .b = 2,
          .c = 7,
          .expected = 1,
      },
      {
          .a = 1,
          .b = 2,
          .c = 3,
          .expected = 0,
      },
  };

  for (const auto &[a, b, c, expected] : test_cases) {
    const auto actual = Solution::minFlips(a, b, c);
    REQUIRE(expected == actual);
  }
}
