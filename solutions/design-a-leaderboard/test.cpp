#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  Leaderboard leaderboard;
  leaderboard.addScore(1, 73);
  leaderboard.addScore(2, 56);
  leaderboard.addScore(3, 39);
  leaderboard.addScore(4, 51);
  leaderboard.addScore(5, 4);
  REQUIRE(73 == leaderboard.top(1));
  leaderboard.reset(1);
  leaderboard.reset(2);
  leaderboard.addScore(2, 51);
  REQUIRE(141 == leaderboard.top(3));
}
