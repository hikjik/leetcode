#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> maze;
    std::vector<int> start;
    std::vector<int> destination;
    bool expected;
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
          .expected = true,
      },
      {
          .maze{{0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0},
                {1, 1, 0, 1, 1},
                {0, 0, 0, 0, 0}},
          .start{0, 4},
          .destination{3, 2},
          .expected = false,
      },
      {
          .maze{{0, 0, 0, 0, 0},
                {1, 1, 0, 0, 1},
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {0, 1, 0, 0, 0}},
          .start{4, 3},
          .destination{0, 1},
          .expected = false,
      },
  };

  for (const auto &[maze, start, destination, expected] : test_cases) {
    const auto actual = Solution::hasPath(maze, start, destination);
    REQUIRE(expected == actual);
  }
}
