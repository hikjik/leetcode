#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .expected = true,
      },
      {
          .n = 7,
          .expected = false,
      },
      {
          .n = 11,
          .expected = false,
      },
      {
          .n = 2147483647,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::hasAlternatingBits(n);
    REQUIRE(expected == actual);
  }
}
