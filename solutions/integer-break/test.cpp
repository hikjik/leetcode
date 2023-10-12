#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected = 1,
      },
      {
          .n = 10,
          .expected = 36,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::integerBreak(n);
    REQUIRE(expected == actual);
  }
}
