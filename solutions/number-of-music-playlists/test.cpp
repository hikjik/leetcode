#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3, goal = 3, k = 1;
    REQUIRE(6 == Solution::numMusicPlaylists(n, goal, k));
  }
  {
    int n = 2, goal = 3, k = 0;
    REQUIRE(6 == Solution::numMusicPlaylists(n, goal, k));
  }
  {
    int n = 2, goal = 3, k = 1;
    REQUIRE(2 == Solution::numMusicPlaylists(n, goal, k));
  }
}
