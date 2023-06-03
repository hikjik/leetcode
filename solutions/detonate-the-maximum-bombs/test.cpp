#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> bombs{{2, 1, 3}, {6, 1, 4}};
    REQUIRE(2 == Solution::maximumDetonation(bombs));
  }
  {
    std::vector<std::vector<int>> bombs{{1, 1, 5}, {10, 10, 5}};
    REQUIRE(1 == Solution::maximumDetonation(bombs));
  }
  {
    std::vector<std::vector<int>> bombs{
        {1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    REQUIRE(5 == Solution::maximumDetonation(bombs));
  }
}
