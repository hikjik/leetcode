#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int a;
    std::vector<int> b;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .a = 2,
          .b{3},
          .expected = 8,
      },
      {
          .a = 2,
          .b{1, 0},
          .expected = 1024,
      },
      {
          .a = 1,
          .b{4, 3, 3, 8, 5, 2},
          .expected = 1,
      },
  };

  for (const auto &[a, b, expected] : test_cases) {
    const auto actual = Solution::superPow(a, b);
    REQUIRE(expected == actual);
  }
}
