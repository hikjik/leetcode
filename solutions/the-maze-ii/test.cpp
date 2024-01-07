#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> maze;
    std::vector<int> start;
    std::vector<int> destination;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .maze{{0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0},
                {1, 1, 0, 1, 1},
                {0, 0, 0, 0, 0}},
          .start{0, 4},
          .destination{4, 4},
          .expected = 12,
      },
      {
          .maze{{0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0},
                {1, 1, 0, 1, 1},
                {0, 0, 0, 0, 0}},
          .start{0, 4},
          .destination{3, 2},
          .expected = -1,
      },
      {
          .maze{{0, 0, 0, 0, 0},
                {1, 1, 0, 0, 1},
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {0, 1, 0, 0, 0}},
          .start{4, 3},
          .destination{0, 1},
          .expected = -1,
      },
  };

  for (const auto &[maze, start, destination, expected] : test_cases) {
    const auto actual = Solution::shortestDistance(maze, start, destination);
    REQUIRE(expected == actual);
  }
}
