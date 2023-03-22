#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 4;
    std::vector<std::vector<int>> roads{
        {1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    REQUIRE(5 == Solution::minScore(n, roads));
  }
  {
    int n = 4;
    std::vector<std::vector<int>> roads{{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
    REQUIRE(2 == Solution::minScore(n, roads));
  }
}
