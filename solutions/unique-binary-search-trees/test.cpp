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
          .expected = 5,
      },
      {
          .n = 1,
          .expected = 1,
      },
  };

  SECTION("Naive") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = naive::Solution::numTrees(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Dynamic Programming") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::numTrees(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Combinatorics") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = combinatorics::Solution::numTrees(n);
      REQUIRE(expected == actual);
    }
  }
}
