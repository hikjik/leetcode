#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> board;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .board{{-1, -1, -1, -1, -1, -1},
                 {-1, -1, -1, -1, -1, -1},
                 {-1, -1, -1, -1, -1, -1},
                 {-1, 35, -1, -1, 13, -1},
                 {-1, -1, -1, -1, -1, -1},
                 {-1, 15, -1, -1, -1, -1}},
          .expected = 4,
      },
      {
          .board{{-1, -1}, {-1, 3}},
          .expected = 1,
      },
  };

  for (const auto &[board, expected] : test_cases) {
    const auto actual = Solution::snakesAndLadders(board);
    REQUIRE(expected == actual);
  }
}
