#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> brackets;
    int income;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .brackets{{3, 50}, {7, 10}, {12, 25}},
          .income = 10,
          .expected = 2.65000,
      },
      {
          .brackets{{1, 0}, {4, 25}, {5, 50}},
          .income = 2,
          .expected = 0.25000,
      },
      {
          .brackets{{2, 50}},
          .income = 0,
          .expected = 0.00000,
      },
  };

  for (const auto &[brackets, income, expected] : test_cases) {
    const auto actual = Solution::calculateTax(brackets, income);
    REQUIRE(expected == Approx(actual));
  }
}
