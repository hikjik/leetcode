#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> regular;
    std::vector<int> express;
    int expressCost;
    std::vector<long long> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .regular{1, 6, 9, 5},
          .express{5, 2, 3, 10},
          .expressCost = 8,
          .expected{1, 7, 14, 19},
      },
      {
          .regular{11, 5, 13},
          .express{7, 10, 6},
          .expressCost = 3,
          .expected{10, 15, 24},
      },
  };

  for (const auto &[regular, express, expressCost, expected] : test_cases) {
    const auto actual = Solution::minimumCosts(regular, express, expressCost);
    REQUIRE(expected == actual);
  }
}
