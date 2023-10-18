#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    double celsius;
    std::vector<double> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .celsius = 36.50,
          .expected{309.65000, 97.70000},
      },
      {
          .celsius = 122.11,
          .expected{395.26000, 251.79800},
      },
  };

  for (const auto &[celsius, expected] : test_cases) {
    const auto actual = Solution::convertTemperature(celsius);
    REQUIRE(expected == actual);
  }
}
