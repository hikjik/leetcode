#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int day;
    int month;
    int year;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .day = 31,
          .month = 8,
          .year = 2019,
          .expected = "Saturday",
      },
      {
          .day = 18,
          .month = 7,
          .year = 1999,
          .expected = "Sunday",
      },
      {
          .day = 15,
          .month = 8,
          .year = 1993,
          .expected = "Sunday",
      },
  };

  for (const auto &[day, month, year, expected] : test_cases) {
    const auto actual = Solution::dayOfTheWeek(day, month, year);
    REQUIRE(expected == actual);
  }
}
