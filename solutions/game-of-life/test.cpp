#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .board{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}},
          .expected{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}},
      },
      {
          .board{{1, 1}, {1, 0}},
          .expected{{1, 1}, {1, 1}},
      },
  };

  for (auto &[board, expected] : test_cases) {
    Solution::gameOfLife(board);
    REQUIRE(expected == board);
  }
}
