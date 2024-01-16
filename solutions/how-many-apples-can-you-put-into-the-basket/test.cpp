#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> weight;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .weight{100, 200, 150, 1000},
          .expected = 4,
      },
      {
          .weight{900, 950, 800, 1000, 700, 800},
          .expected = 5,
      },
  };

  for (const auto &[weight, expected] : test_cases) {
    const auto actual = Solution::maxNumberOfApples(weight);
    REQUIRE(expected == actual);
  }
}
