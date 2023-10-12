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
          .num1 = "2",
          .num2 = "3",
          .expected = "6",
      },
      {
          .num1 = "123",
          .num2 = "456",
          .expected = "56088",
      },
  };

  for (const auto &[num1, num2, expected] : test_cases) {
    const auto actual = Solution::multiply(num1, num2);
    REQUIRE(expected == actual);
  }
}
