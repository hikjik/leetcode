#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> position;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .position{1, 2, 3},
          .expected = 1,
      },
      {
          .position{2, 2, 2, 3, 3},
          .expected = 2,
      },
      {
          .position{1, 1000000000},
          .expected = 1,
      },
  };

  for (const auto &[position, expected] : test_cases) {
    const auto actual = Solution::minCostToMoveChips(position);
    REQUIRE(expected == actual);
  }
}
