#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> maze;
    std::vector<int> ball;
    std::vector<int> hole;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .maze{{0, 0, 0, 0, 0},
                {1, 1, 0, 0, 1},
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {0, 1, 0, 0, 0}},
          .ball{4, 3},
          .hole{0, 1},
          .expected = "lul",
      },
      {
          .maze{{0, 0, 0, 0, 0},
                {1, 1, 0, 0, 1},
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {0, 1, 0, 0, 0}},
          .ball{4, 3},
          .hole{3, 0},
          .expected = "impossible",
      },
      {
          .maze{{0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 1, 0},
                {0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 1}},
          .ball{0, 4},
          .hole{3, 5},
          .expected = "dldr",
      },
  };

  for (const auto &[maze, ball, hole, expected] : test_cases) {
    const auto actual = Solution::findShortestWay(maze, ball, hole);
    REQUIRE(expected == actual);
  }
}
