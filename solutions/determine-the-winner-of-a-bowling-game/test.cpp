#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> player1;
    std::vector<int> player2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .player1{4, 10, 7, 9},
          .player2{6, 5, 2, 3},
          .expected = 1,
      },
      {
          .player1{3, 5, 7, 6},
          .player2{8, 10, 10, 2},
          .expected = 2,
      },
      {
          .player1{2, 3},
          .player2{4, 1},
          .expected = 0,
      },
  };

  for (const auto &[player1, player2, expected] : test_cases) {
    const auto actual = Solution::isWinner(player1, player2);
    REQUIRE(expected == actual);
  }
}
