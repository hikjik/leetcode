#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int n = 3;
  auto tic_tac_toe = TicTacToe(n);

  REQUIRE(0 == tic_tac_toe.move(0, 0, 1));
  REQUIRE(0 == tic_tac_toe.move(0, 2, 2));
  REQUIRE(0 == tic_tac_toe.move(2, 2, 1));
  REQUIRE(0 == tic_tac_toe.move(1, 1, 2));
  REQUIRE(0 == tic_tac_toe.move(2, 0, 1));
  REQUIRE(0 == tic_tac_toe.move(1, 0, 2));
  REQUIRE(1 == tic_tac_toe.move(2, 1, 1));
}
