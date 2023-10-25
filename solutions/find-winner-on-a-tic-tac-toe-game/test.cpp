#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> moves;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .moves{{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}},
          .expected = "A",
      },
      {
          .moves{{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}},
          .expected = "B",
      },
      {
          .moves{{0, 0},
                 {1, 1},
                 {2, 0},
                 {1, 0},
                 {1, 2},
                 {2, 1},
                 {0, 1},
                 {0, 2},
                 {2, 2}},
          .expected = "Draw",
      },
  };

  for (const auto &[moves, expected] : test_cases) {
    const auto actual = Solution::tictactoe(moves);
    REQUIRE(expected == actual);
  }
}
