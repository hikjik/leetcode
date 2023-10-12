#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .expected = 2,
      },
      {
          .n = 8,
          .expected = 3,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::arrangeCoins(n);
    REQUIRE(expected == actual);
  }
}
