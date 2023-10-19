#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string date;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .date = "2019-02-10",
          .expected = 41,
      },
      {
          .date = "2019-01-09",
          .expected = 9,
      },
      {
          .date = "2000-12-31",
          .expected = 366,
      },
  };

  for (const auto &[date, expected] : test_cases) {
    const auto actual = Solution::dayOfYear(date);
    REQUIRE(expected == actual);
  }
}
