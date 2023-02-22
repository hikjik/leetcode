#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> accounts{{1, 2, 3}, {3, 2, 1}};
    REQUIRE(6 == Solution::maximumWealth(accounts));
  }
  {
    std::vector<std::vector<int>> accounts{{1, 5}, {7, 3}, {3, 5}};
    REQUIRE(10 == Solution::maximumWealth(accounts));
  }
  {
    std::vector<std::vector<int>> accounts{{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
    REQUIRE(17 == Solution::maximumWealth(accounts));
  }
}
