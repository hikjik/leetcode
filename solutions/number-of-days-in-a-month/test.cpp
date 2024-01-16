#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int year;
    int month;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .year = 1992,
          .month = 7,
          .expected = 31,
      },
      {
          .year = 2000,
          .month = 2,
          .expected = 29,
      },
      {
          .year = 1900,
          .month = 2,
          .expected = 28,
      },
  };

  for (const auto &[year, month, expected] : test_cases) {
    const auto actual = Solution::numberOfDays(year, month);
    REQUIRE(expected == actual);
  }
}
