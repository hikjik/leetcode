#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int columnNumber;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .columnNumber = 1,
          .expected = "A",
      },
      {
          .columnNumber = 28,
          .expected = "AB",
      },
      {
          .columnNumber = 701,
          .expected = "ZY",
      },
  };

  for (const auto &[columnNumber, expected] : test_cases) {
    const auto actual = Solution::convertToTitle(columnNumber);
    REQUIRE(expected == actual);
  }
}
