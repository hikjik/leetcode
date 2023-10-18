#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 17,
          .expected{2, 0},
      },
      {
          .n = 2,
          .expected{0, 1},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::evenOddBit(n);
    REQUIRE(expected == actual);
  }
}
