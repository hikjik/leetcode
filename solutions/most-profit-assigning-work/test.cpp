#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> difficulty;
    std::vector<int> profit;
    std::vector<int> worker;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .difficulty{2, 4, 6, 8, 10},
          .profit{10, 20, 30, 40, 50},
          .worker{4, 5, 6, 7},
          .expected = 100,
      },
      {
          .difficulty{85, 47, 57},
          .profit{24, 66, 99},
          .worker{40, 25, 25},
          .expected = 0,
      },
  };

  for (const auto &[difficulty, profit, worker, expected] : test_cases) {
    const auto actual =
        Solution::maxProfitAssignment(difficulty, profit, worker);
    REQUIRE(expected == actual);
  }
}
