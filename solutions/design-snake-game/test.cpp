#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int width = 3;
    int height = 2;
    std::vector<std::vector<int>> food{{1, 2}, {0, 1}};
    auto snake_game = SnakeGame(width, height, food);

    REQUIRE(0 == snake_game.move("R"));
    REQUIRE(0 == snake_game.move("D"));
    REQUIRE(1 == snake_game.move("R"));
    REQUIRE(1 == snake_game.move("U"));
    REQUIRE(2 == snake_game.move("L"));
    REQUIRE(-1 == snake_game.move("U"));
  }
}
