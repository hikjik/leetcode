#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .expected = 10,
      },
      {
          .n = 6,
          .expected = 6,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::smallestEvenMultiple(n);
    REQUIRE(expected == actual);
  }
}
