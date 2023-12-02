#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .expected = 12,
      },
      {
          .n = 5000,
          .expected = 30228214,
      },
  };

  SECTION("DP") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::numOfWays(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Algebra") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = algebra::Solution::numOfWays(n);
      REQUIRE(expected == actual);
    }
  }
}
