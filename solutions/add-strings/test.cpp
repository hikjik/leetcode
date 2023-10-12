#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string num1;
    std::string num2;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num1 = "11",
          .num2 = "123",
          .expected = "134",
      },
      {
          .num1 = "456",
          .num2 = "77",
          .expected = "533",
      },
      {
          .num1 = "0",
          .num2 = "0",
          .expected = "0",
      },
      {
          .num1 = "50",
          .num2 = "50",
          .expected = "100",
      },
  };

  for (const auto &[num1, num2, expected] : test_cases) {
    const auto actual = Solution::addStrings(num1, num2);
    REQUIRE(expected == actual);
  }
}
