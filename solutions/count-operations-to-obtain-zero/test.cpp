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
          .num1 = 2,
          .num2 = 3,
          .expected = 3,
      },
      {
          .num1 = 10,
          .num2 = 10,
          .expected = 1,
      },
  };

  for (const auto &[num1, num2, expected] : test_cases) {
    const auto actual = Solution::countOperations(num1, num2);
    REQUIRE(expected == actual);
  }
}
