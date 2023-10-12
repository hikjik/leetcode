#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 10,
          .expected = 12,
      },
      {
          .n = 1,
          .expected = 1,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::nthUglyNumber(n);
    REQUIRE(expected == actual);
  }
}
