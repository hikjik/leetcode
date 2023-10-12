#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> board;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .board{{1, 2, 3}, {4, 0, 5}},
          .expected = 1,
      },
      {
          .board{{1, 2, 3}, {5, 4, 0}},
          .expected = -1,
      },
      {
          .board{{4, 1, 2}, {5, 0, 3}},
          .expected = 5,
      },
  };

  for (const auto &[board, expected] : test_cases) {
    const auto actual = Solution::slidingPuzzle(board);
    REQUIRE(expected == actual);
  }
}
