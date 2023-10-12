#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> heights;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}},
          .expected = 2,
      },
      {
          .heights{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}},
          .expected = 1,
      },
      {
          .heights{{1, 2, 1, 1, 1},
                   {1, 2, 1, 2, 1},
                   {1, 2, 1, 2, 1},
                   {1, 2, 1, 2, 1},
                   {1, 1, 1, 2, 1}},
          .expected = 0,
      },
  };

  for (const auto &[heights, expected] : test_cases) {
    const auto actual = Solution::minimumEffortPath(heights);
    REQUIRE(expected == actual);
  }
}
