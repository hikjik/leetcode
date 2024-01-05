#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int numPeople;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .numPeople = 0,
          .expected = 1,
      },
      {
          .numPeople = 2,
          .expected = 1,
      },
      {
          .numPeople = 4,
          .expected = 2,
      },
      {
          .numPeople = 6,
          .expected = 5,
      },
      {
          .numPeople = 8,
          .expected = 14,
      },
  };

  SECTION("Tabulation") {
    for (const auto &[numPeople, expected] : test_cases) {
      const auto actual = dp::Solution::numberOfWays(numPeople);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Math") {
    for (const auto &[numPeople, expected] : test_cases) {
      const auto actual = math::Solution::numberOfWays(numPeople);
      REQUIRE(expected == actual);
    }
  }
}
