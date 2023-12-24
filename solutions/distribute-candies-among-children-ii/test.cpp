#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int limit;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .limit = 2,
          .expected = 3,
      },
      {
          .n = 3,
          .limit = 3,
          .expected = 10,
      },
  };

  SECTION("Linear") {
    for (const auto &[n, limit, expected] : test_cases) {
      const auto actual = linear::Solution::distributeCandies(n, limit);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Combinatorics") {
    for (const auto &[n, limit, expected] : test_cases) {
      const auto actual = combinatorics::Solution::distributeCandies(n, limit);
      REQUIRE(expected == actual);
    }
  }
}
