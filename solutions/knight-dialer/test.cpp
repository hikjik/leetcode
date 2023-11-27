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
          .expected = 10,
      },
      {
          .n = 2,
          .expected = 20,
      },
      {
          .n = 3131,
          .expected = 136006598,
      },
  };

  SECTION("DP") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::knightDialer(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Symmetry") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = symmetry::Solution::knightDialer(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Linear Algebra") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = la::Solution::knightDialer(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Linear Algebra + Symmetry") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = la_symmetry::Solution::knightDialer(n);
      REQUIRE(expected == actual);
    }
  }
}
