#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num1;
    int num2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num1 = 12,
          .num2 = 5,
          .expected = 17,
      },
      {
          .num1 = -10,
          .num2 = 4,
          .expected = -6,
      },
  };

  for (const auto &[num1, num2, expected] : test_cases) {
    const auto actual = Solution::sum(num1, num2);
    REQUIRE(expected == actual);
  }
}
