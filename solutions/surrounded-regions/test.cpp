#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> board;
    std::vector<std::vector<char>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .board{{'X', 'X', 'X', 'X'},
                 {'X', 'O', 'O', 'X'},
                 {'X', 'X', 'O', 'X'},
                 {'X', 'O', 'X', 'X'}},
          .expected{{'X', 'X', 'X', 'X'},
                    {'X', 'X', 'X', 'X'},
                    {'X', 'X', 'X', 'X'},
                    {'X', 'O', 'X', 'X'}},
      },
      {
          .board{{'X'}},
          .expected{{'X'}},
      },
  };

  for (auto &[board, expected] : test_cases) {
    Solution::solve(board);
    REQUIRE(expected == board);
  }
}
