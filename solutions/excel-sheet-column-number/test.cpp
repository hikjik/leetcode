#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string columnTitle;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .columnTitle = "A",
          .expected = 1,
      },
      {
          .columnTitle = "AB",
          .expected = 28,
      },
      {
          .columnTitle = "ZY",
          .expected = 701,
      },
  };

  for (const auto &[columnTitle, expected] : test_cases) {
    const auto actual = Solution::titleToNumber(columnTitle);
    REQUIRE(expected == actual);
  }
}
