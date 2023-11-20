#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .expected = 3,
      },
      {
          .n = 11,
          .expected = 0,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::findNthDigit(n);
    REQUIRE(expected == actual);
  }
}
