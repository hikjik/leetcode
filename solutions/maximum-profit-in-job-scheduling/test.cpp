#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> startTime;
    std::vector<int> endTime;
    std::vector<int> profit;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .startTime{1, 2, 3, 3},
          .endTime{3, 4, 5, 6},
          .profit{50, 10, 40, 70},
          .expected = 120,
      },
      {
          .startTime{1, 2, 3, 4, 6},
          .endTime{3, 5, 10, 6, 9},
          .profit{20, 20, 100, 70, 60},
          .expected = 150,
      },
      {
          .startTime{1, 1, 1},
          .endTime{2, 3, 4},
          .profit{5, 6, 4},
          .expected = 6,
      },
  };

  SECTION("Memoization") {
    for (const auto &[startTime, endTime, profit, expected] : test_cases) {
      const auto actual =
          memo::Solution::jobScheduling(startTime, endTime, profit);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[startTime, endTime, profit, expected] : test_cases) {
      const auto actual =
          dp::Solution::jobScheduling(startTime, endTime, profit);
      REQUIRE(expected == actual);
    }
  }
}
