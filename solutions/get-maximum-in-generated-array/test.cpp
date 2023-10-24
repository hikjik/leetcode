#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 7,
          .expected = 3,
      },
      {
          .n = 2,
          .expected = 1,
      },
      {
          .n = 3,
          .expected = 2,
      },
      {
          .n = 0,
          .expected = 0,
      },
      {
          .n = 1,
          .expected = 1,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::getMaximumGenerated(n);
    REQUIRE(expected == actual);
  }
}
