#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int numerator;
    int denominator;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .numerator = 1,
          .denominator = 2,
          .expected = "0.5",
      },
      {
          .numerator = 2,
          .denominator = 1,
          .expected = "2",
      },
      {
          .numerator = 4,
          .denominator = 333,
          .expected = "0.(012)",
      },
      {
          .numerator = 0,
          .denominator = -2,
          .expected = "0",
      },
      {
          .numerator = 1,
          .denominator = -2,
          .expected = "-0.5",
      },
      {
          .numerator = 0,
          .denominator = 3,
          .expected = "0",
      },
      {
          .numerator = -50,
          .denominator = 8,
          .expected = "-6.25",
      },
      {
          .numerator = -1,
          .denominator = -2147483648,
          .expected = "0.0000000004656612873077392578125",
      },
  };

  for (const auto &[numerator, denominator, expected] : test_cases) {
    const auto actual = Solution::fractionToDecimal(numerator, denominator);
    REQUIRE(expected == actual);
  }
}
