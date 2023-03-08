#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int h = 8;
    std::vector<int> piles{3, 6, 7, 11};
    REQUIRE(4 == Solution::minEatingSpeed(piles, h));
  }
  {
    int h = 5;
    std::vector<int> piles{30, 11, 23, 4, 20};
    REQUIRE(30 == Solution::minEatingSpeed(piles, h));
  }
  {
    int h = 6;
    std::vector<int> piles{30, 11, 23, 4, 20};
    REQUIRE(23 == Solution::minEatingSpeed(piles, h));
  }
}
