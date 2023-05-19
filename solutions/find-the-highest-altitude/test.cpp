#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> gain{-5, 1, 5, 0, -7};
    REQUIRE(1 == Solution::largestAltitude(gain));
  }
  {
    std::vector<int> gain{-4, -3, -2, -1, 4, 3, 2};
    REQUIRE(0 == Solution::largestAltitude(gain));
  }
}
