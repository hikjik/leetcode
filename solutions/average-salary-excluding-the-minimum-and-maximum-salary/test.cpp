#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> salary;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .salary{4000, 3000, 1000, 2000},
          .expected = 2500.00000,
      },
      {
          .salary{1000, 2000, 3000},
          .expected = 2000.00000,
      },
  };

  for (const auto &[salary, expected] : test_cases) {
    const auto actual = Solution::average(salary);
    REQUIRE(expected == Approx(actual));
  }
}
