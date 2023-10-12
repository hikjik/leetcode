#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> heights;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{{1, 2, 2, 3, 5},
                   {3, 2, 3, 4, 4},
                   {2, 4, 5, 3, 1},
                   {6, 7, 1, 4, 5},
                   {5, 1, 1, 2, 4}},
          .expected{{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}},
      },
      {
          .heights{{1}},
          .expected{{0, 0}},
      },
  };

  for (const auto &[heights, expected] : test_cases) {
    const auto actual = Solution::pacificAtlantic(heights);
    REQUIRE(expected == actual);
  }
}
