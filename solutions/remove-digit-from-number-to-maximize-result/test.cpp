#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string number;
    char digit;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .number = "123",
          .digit = '3',
          .expected = "12",
      },
      {
          .number = "1231",
          .digit = '1',
          .expected = "231",
      },
      {
          .number = "551",
          .digit = '5',
          .expected = "51",
      },
  };

  for (const auto &[number, digit, expected] : test_cases) {
    const auto actual = Solution::removeDigit(number, digit);
    REQUIRE(expected == actual);
  }
}
