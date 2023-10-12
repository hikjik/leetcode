#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> maze;
    std::vector<int> entrance;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .maze{
              {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}},
          .entrance{1, 2},
          .expected = 1,
      },
      {
          .maze{{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}},
          .entrance{1, 0},
          .expected = 2,
      },
      {
          .maze{{'.', '+'}},
          .entrance{0, 0},
          .expected = -1,
      },
  };

  for (const auto &[maze, entrance, expected] : test_cases) {
    const auto actual = Solution::nearestExit(maze, entrance);
    REQUIRE(expected == actual);
  }
}
