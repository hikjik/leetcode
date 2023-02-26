#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 6;
    std::vector<std::vector<int>> connections{
        {0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    REQUIRE(3 == Solution::minReorder(n, connections));
  }
  {
    int n = 5;
    std::vector<std::vector<int>> connections{{1, 0}, {1, 2}, {3, 2}, {3, 4}};
    REQUIRE(2 == Solution::minReorder(n, connections));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> connections{{1, 0}, {2, 0}};
    REQUIRE(0 == Solution::minReorder(n, connections));
  }
  {
    int n = 5;
    std::vector<std::vector<int>> connections{{4, 3}, {2, 3}, {1, 2}, {1, 0}};
    REQUIRE(2 == Solution::minReorder(n, connections));
  }
}
