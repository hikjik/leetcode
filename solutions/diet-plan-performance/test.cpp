#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> calories;
    int k;
    int lower;
    int upper;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .calories{1, 2, 3, 4, 5},
          .k = 1,
          .lower = 3,
          .upper = 3,
          .expected = 0,
      },
      {
          .calories{3, 2},
          .k = 2,
          .lower = 0,
          .upper = 1,
          .expected = 1,
      },
      {
          .calories{6, 5, 0, 0},
          .k = 2,
          .lower = 1,
          .upper = 5,
          .expected = 0,
      },
  };

  for (const auto &[calories, k, lower, upper, expected] : test_cases) {
    const auto actual =
        Solution::dietPlanPerformance(calories, k, lower, upper);
    REQUIRE(expected == actual);
  }
}
