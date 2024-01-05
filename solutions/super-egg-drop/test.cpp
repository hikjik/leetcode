#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int k;
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .k = 1,
          .n = 2,
          .expected = 2,
      },
      {
          .k = 2,
          .n = 6,
          .expected = 3,
      },
      {
          .k = 3,
          .n = 14,
          .expected = 4,
      },
      {
          .k = 3,
          .n = 25,
          .expected = 5,
      },
  };

  SECTION("Memoization") {
    for (const auto &[k, n, expected] : test_cases) {
      const auto actual = memo::Solution::superEggDrop(k, n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[k, n, expected] : test_cases) {
      const auto actual = dp::Solution::superEggDrop(k, n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation 2") {
    for (const auto &[k, n, expected] : test_cases) {
      const auto actual = dp2::Solution::superEggDrop(k, n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation 2 Optimized") {
    for (const auto &[k, n, expected] : test_cases) {
      const auto actual = dp2_opt::Solution::superEggDrop(k, n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Math") {
    for (const auto &[k, n, expected] : test_cases) {
      const auto actual = dp2_math::Solution::superEggDrop(k, n);
      REQUIRE(expected == actual);
    }
  }
}
