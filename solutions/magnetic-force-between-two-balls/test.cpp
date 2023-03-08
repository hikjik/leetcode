#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> positions{1, 2, 3, 4, 7};
    int m = 3;
    REQUIRE(3 == Solution::maxDistance(positions, m));
  }
  {
    std::vector<int> positions{5, 4, 3, 2, 1, 1000000000};
    int m = 2;
    REQUIRE(999999999 == Solution::maxDistance(positions, m));
  }
}
