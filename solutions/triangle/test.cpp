#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> triangle{
        {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    REQUIRE(11 == Solution::minimumTotal(triangle));
  }
  {
    std::vector<std::vector<int>> triangle{{-10}};
    REQUIRE(-10 == Solution::minimumTotal(triangle));
  }
}
