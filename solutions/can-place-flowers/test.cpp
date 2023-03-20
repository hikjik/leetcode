#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 1;
    std::vector<int> flowerbed{1, 0, 0, 0, 1};
    REQUIRE(Solution::canPlaceFlowers(flowerbed, n));
  }
  {
    int n = 2;
    std::vector<int> flowerbed{1, 0, 0, 0, 1};
    REQUIRE_FALSE(Solution::canPlaceFlowers(flowerbed, n));
  }
}
