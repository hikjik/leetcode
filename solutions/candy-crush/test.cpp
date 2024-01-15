#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .board{{110, 5, 112, 113, 114},
                 {210, 211, 5, 213, 214},
                 {310, 311, 3, 313, 314},
                 {410, 411, 412, 5, 414},
                 {5, 1, 512, 3, 3},
                 {610, 4, 1, 613, 614},
                 {710, 1, 2, 713, 714},
                 {810, 1, 2, 1, 1},
                 {1, 1, 2, 2, 2},
                 {4, 1, 4, 4, 1014}},
          .expected{{0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {110, 0, 0, 0, 114},
                    {210, 0, 0, 0, 214},
                    {310, 0, 0, 113, 314},
                    {410, 0, 0, 213, 414},
                    {610, 211, 112, 313, 614},
                    {710, 311, 412, 613, 714},
                    {810, 411, 512, 713, 1014}},
      },
      {
          .board{{1, 3, 5, 5, 2},
                 {3, 4, 3, 3, 1},
                 {3, 2, 4, 5, 2},
                 {2, 4, 4, 5, 5},
                 {1, 4, 4, 1, 1}},
          .expected{{1, 3, 0, 0, 0},
                    {3, 4, 0, 5, 2},
                    {3, 2, 0, 3, 1},
                    {2, 4, 0, 5, 2},
                    {1, 4, 3, 1, 1}},
      },
  };

  for (const auto &[board, expected] : test_cases) {
    const auto actual = Solution::candyCrush(board);
    REQUIRE(expected == actual);
  }
}
