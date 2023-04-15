#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 9;
    std::vector<std::vector<int>> piles{
        {37, 88}, {51, 64, 65, 20, 95, 30, 26}, {9, 62, 20}, {44}};
    REQUIRE(494 == Solution::maxValueOfCoins(piles, k));
  }
  {
    int k = 2;
    std::vector<std::vector<int>> piles{{1, 100, 3}, {7, 8, 9}};
    REQUIRE(101 == Solution::maxValueOfCoins(piles, k));
  }
  {
    int k = 7;
    std::vector<std::vector<int>> piles{
        {100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700}};
    REQUIRE(706 == Solution::maxValueOfCoins(piles, k));
  }
}
