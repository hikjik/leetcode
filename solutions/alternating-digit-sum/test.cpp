#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 521,
          .expected = 4,
      },
      {
          .n = 111,
          .expected = 1,
      },
      {
          .n = 886996,
          .expected = 0,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::alternateDigitSum(n);
    REQUIRE(expected == actual);
  }
}
