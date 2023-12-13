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
          .num1 = "1+1i",
          .num2 = "1+1i",
          .expected = "0+2i",
      },
      {
          .num1 = "1+-1i",
          .num2 = "1+-1i",
          .expected = "0+-2i",
      },
  };

  for (const auto &[num1, num2, expected] : test_cases) {
    const auto actual = Solution::complexNumberMultiply(num1, num2);
    REQUIRE(expected == actual);
  }
}
