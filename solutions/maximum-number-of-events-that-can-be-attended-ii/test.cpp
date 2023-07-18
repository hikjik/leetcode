#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<std::vector<int>> events{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    REQUIRE(7 == Solution::maxValue(events, k));
  }
  {
    int k = 2;
    std::vector<std::vector<int>> events{{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    REQUIRE(10 == Solution::maxValue(events, k));
  }
  {
    int k = 3;
    std::vector<std::vector<int>> events{
        {1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
    REQUIRE(9 == Solution::maxValue(events, k));
  }
}
