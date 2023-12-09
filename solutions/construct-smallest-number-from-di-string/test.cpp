#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string pattern;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .pattern = "IIIDIDDD",
          .expected = "123549876",
      },
      {
          .pattern = "DDD",
          .expected = "4321",
      },
  };

  SECTION("Brute Force") {
    for (const auto &[pattern, expected] : test_cases) {
      const auto actual = brute_force::Solution::smallestNumber(pattern);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Stack") {
    for (const auto &[pattern, expected] : test_cases) {
      const auto actual = stack::Solution::smallestNumber(pattern);
      REQUIRE(expected == actual);
    }
  }
}
