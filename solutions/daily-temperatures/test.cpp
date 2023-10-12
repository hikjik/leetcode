#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> temperatures;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .temperatures{73, 74, 75, 71, 69, 72, 76, 73},
          .expected{1, 1, 4, 2, 1, 1, 0, 0},
      },
      {
          .temperatures{30, 40, 50, 60},
          .expected{1, 1, 1, 0},
      },
      {
          .temperatures{30, 60, 90},
          .expected{1, 1, 0},
      },
  };

  for (const auto &[temperatures, expected] : test_cases) {
    const auto actual = Solution::dailyTemperatures(temperatures);
    REQUIRE(expected == actual);
  }
}
