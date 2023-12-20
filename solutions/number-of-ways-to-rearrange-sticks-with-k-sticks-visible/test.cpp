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
          .n = 3,
          .k = 2,
          .expected = 3,
      },
      {
          .n = 5,
          .k = 5,
          .expected = 1,
      },
      {
          .n = 20,
          .k = 11,
          .expected = 647427950,
      },
      {
          .n = 1000,
          .k = 500,
          .expected = 761367694,
      },
  };

  SECTION("Tabulation") {
    for (const auto &[n, k, expected] : test_cases) {
      const auto actual = dp::Solution::rearrangeSticks(n, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[n, k, expected] : test_cases) {
      const auto actual = memo::Solution::rearrangeSticks(n, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[n, k, expected] : test_cases) {
      const auto actual = optimized::Solution::rearrangeSticks(n, k);
      REQUIRE(expected == actual);
    }
  }
}
