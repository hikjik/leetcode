#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string date;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .date = "20th Oct 2052",
          .expected = "2052-10-20",
      },
      {
          .date = "6th Jun 1933",
          .expected = "1933-06-06",
      },
      {
          .date = "26th May 1960",
          .expected = "1960-05-26",
      },
  };

  for (const auto &[date, expected] : test_cases) {
    const auto actual = Solution::reformatDate(date);
    REQUIRE(expected == actual);
  }
}
