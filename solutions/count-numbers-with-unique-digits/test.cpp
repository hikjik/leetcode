#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 0,
          .expected = 1,
      },
      {
          .n = 1,
          .expected = 10,
      },
      {
          .n = 2,
          .expected = 91,
      },
      {
          .n = 3,
          .expected = 739,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countNumbersWithUniqueDigits(n);
    REQUIRE(expected == actual);
  }
}
