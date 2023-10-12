#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 13,
          .expected = 6,
      },
      {
          .n = 0,
          .expected = 0,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countDigitOne(n);
    REQUIRE(expected == actual);
  }
}
