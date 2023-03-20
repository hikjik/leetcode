#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> asteroids{5, 10, -5};
    std::vector<int> expected{5, 10};
    REQUIRE(expected == Solution::asteroidCollision(asteroids));
  }
  {
    std::vector<int> asteroids{8, -8};
    std::vector<int> expected;
    REQUIRE(expected == Solution::asteroidCollision(asteroids));
  }
  {
    std::vector<int> asteroids{10, 2, -5};
    std::vector<int> expected{10};
    REQUIRE(expected == Solution::asteroidCollision(asteroids));
  }
  {
    std::vector<int> asteroids{-2, -1, 1, 2};
    std::vector<int> expected{-2, -1, 1, 2};
    REQUIRE(expected == Solution::asteroidCollision(asteroids));
  }
}
