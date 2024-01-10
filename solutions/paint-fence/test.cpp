#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .k = 2,
          .expected = 6,
      },
      {
          .n = 1,
          .k = 1,
          .expected = 1,
      },
      {
          .n = 7,
          .k = 2,
          .expected = 42,
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::numWays(n, k);
    REQUIRE(expected == actual);
  }
}
