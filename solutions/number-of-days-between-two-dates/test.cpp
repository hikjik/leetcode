#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string date1;
    std::string date2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .date1 = "2019-06-29",
          .date2 = "2019-06-30",
          .expected = 1,
      },
      {
          .date1 = "2020-01-15",
          .date2 = "2019-12-31",
          .expected = 15,
      },
  };

  for (const auto &[date1, date2, expected] : test_cases) {
    const auto actual = Solution::daysBetweenDates(date1, date2);
    REQUIRE(expected == actual);
  }
}
