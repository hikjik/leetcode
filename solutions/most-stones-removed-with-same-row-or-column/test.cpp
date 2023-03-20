#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> stones{{0, 0}, {0, 1}, {1, 0},
                                         {1, 2}, {2, 1}, {2, 2}};
    REQUIRE(5 == Solution::removeStones(stones));
  }
  {
    std::vector<std::vector<int>> stones{
        {0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    REQUIRE(3 == Solution::removeStones(stones));
  }
  {
    std::vector<std::vector<int>> stones{{0, 0}};
    REQUIRE(0 == Solution::removeStones(stones));
  }
}
