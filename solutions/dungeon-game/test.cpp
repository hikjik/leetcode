#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> dungeon;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}},
          .expected = 7,
      },
      {
          .dungeon{{0}},
          .expected = 1,
      },
  };

  // SECTION("Memoization") {
  //   for (const auto &[dungeon, expected] : test_cases) {
  //     const auto actual = memo::Solution::calculateMinimumHP(dungeon);
  //     REQUIRE(expected == actual);
  //   }
  // }

  // SECTION("Tabulation") {
  //   for (const auto &[dungeon, expected] : test_cases) {
  //     const auto actual = dp::Solution::calculateMinimumHP(dungeon);
  //     REQUIRE(expected == actual);
  //   }
  // }

  SECTION("Optimized") {
    for (const auto &[dungeon, expected] : test_cases) {
      const auto actual = optimized::Solution::calculateMinimumHP(dungeon);
      REQUIRE(expected == actual);
    }
  }
}
