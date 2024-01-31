#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> heights;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{4, 2, 3, 1},
          .expected{0, 2, 3},
      },
      {
          .heights{4, 3, 2, 1},
          .expected{0, 1, 2, 3},
      },
      {
          .heights{1, 3, 2, 4},
          .expected{3},
      },
      {
          .heights{2, 2, 2, 2},
          .expected{3},
      },
  };

  for (const auto &[heights, expected] : test_cases) {
    const auto actual = Solution::findBuildings(heights);
    REQUIRE(expected == actual);
  }
}
