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
          .expected = 0,
      },
      {
          .n = 2,
          .expected = 1,
      },
      {
          .n = 3,
          .expected = 2,
      },
      {
          .n = 6,
          .expected = 9,
      },
  };

  SECTION("") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = linear::Solution::minOperations(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = constant::Solution::minOperations(n);
      REQUIRE(expected == actual);
    }
  }
}
