#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> land;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .land{{1, 0, 0}, {0, 1, 1}, {0, 1, 1}},
          .expected{{0, 0, 0, 0}, {1, 1, 2, 2}},
      },
      {
          .land{{1, 1}, {1, 1}},
          .expected{{0, 0, 1, 1}},
      },
      {
          .land{{0}},
          .expected{},
      },
  };

  for (const auto &[land, expected] : test_cases) {
    const auto actual = Solution::findFarmland(land);
    REQUIRE(expected == actual);
  }
}
