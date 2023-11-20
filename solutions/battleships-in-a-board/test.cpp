#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> board;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .board{
              {'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}},
          .expected = 2,
      },
      {
          .board{{'.'}},
          .expected = 0,
      },
  };

  for (const auto &[board, expected] : test_cases) {
    const auto actual = Solution::countBattleships(board);
    REQUIRE(expected == actual);
  }
}
