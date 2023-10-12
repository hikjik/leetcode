#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> forbidden;
    int a;
    int b;
    int x;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .forbidden{14, 4, 18, 1, 15},
          .a = 3,
          .b = 15,
          .x = 9,
          .expected = 3,
      },
      {
          .forbidden{8, 3, 16, 6, 12, 20},
          .a = 15,
          .b = 13,
          .x = 11,
          .expected = -1,
      },
      {
          .forbidden{1, 6, 2, 14, 5, 17, 4},
          .a = 16,
          .b = 9,
          .x = 7,
          .expected = 2,
      },
  };

  for (const auto &[forbidden, a, b, x, expected] : test_cases) {
    const auto actual = Solution::minimumJumps(forbidden, a, b, x);
    REQUIRE(expected == actual);
  }
}
