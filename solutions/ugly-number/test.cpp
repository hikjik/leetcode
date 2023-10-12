#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 6,
          .expected = true,
      },
      {
          .n = 1,
          .expected = true,
      },
      {
          .n = 14,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::isUgly(n);
    REQUIRE(expected == actual);
  }
}
