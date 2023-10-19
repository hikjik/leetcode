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
          .expected = 12,
      },
      {
          .n = 100,
          .expected = 682289015,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::numPrimeArrangements(n);
    REQUIRE(expected == actual);
  }
}
