#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> board;
    std::string word;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .board{
              {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
          .word = "ABCCED",
          .expected = true,
      },
      {
          .board{
              {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
          .word = "SEE",
          .expected = true,
      },
      {
          .board{
              {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
          .word = "ABCB",
          .expected = false,
      },
  };

  for (const auto &[board, word, expected] : test_cases) {
    const auto actual = Solution::exist(board, word);
    REQUIRE(expected == actual);
  }
}
