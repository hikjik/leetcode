#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 9,
          .expected = false,
      },
      {
          .n = 4,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::isStrictlyPalindromic(n);
    REQUIRE(expected == actual);
  }
}
