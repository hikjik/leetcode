#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 8,
          .expected = 6,
      },
      {
          .n = 1,
          .expected = 1,
      },
      {
          .n = 4,
          .expected = -1,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::pivotInteger(n);
    REQUIRE(expected == actual);
  }
}
