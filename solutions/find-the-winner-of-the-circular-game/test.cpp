#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .k = 2,
          .expected = 3,
      },
      {
          .n = 6,
          .k = 5,
          .expected = 1,
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::findTheWinner(n, k);
    REQUIRE(expected == actual);
  }
}
