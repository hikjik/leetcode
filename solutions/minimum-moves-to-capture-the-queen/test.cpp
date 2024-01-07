#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .a = 1,
          .b = 1,
          .c = 8,
          .d = 8,
          .e = 2,
          .f = 3,
          .expected = 2,
      },
      {
          .a = 5,
          .b = 3,
          .c = 3,
          .d = 4,
          .e = 5,
          .f = 2,
          .expected = 1,
      },
  };

  for (const auto &[a, b, c, d, e, f, expected] : test_cases) {
    const auto actual = Solution::minMovesToCaptureTheQueen(a, b, c, d, e, f);
    REQUIRE(expected == actual);
  }
}
