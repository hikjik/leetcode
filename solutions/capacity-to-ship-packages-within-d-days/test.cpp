#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> weights;
    int days;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
          .days = 5,
          .expected = 15,
      },
      {
          .weights{3, 2, 2, 4, 1, 4},
          .days = 3,
          .expected = 6,
      },
      {
          .weights{1, 2, 3, 1, 1},
          .days = 4,
          .expected = 3,
      },
  };

  for (const auto &[weights, days, expected] : test_cases) {
    const auto actual = Solution::shipWithinDays(weights, days);
    REQUIRE(expected == actual);
  }
}
