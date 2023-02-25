#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> isConnected{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    REQUIRE(2 == Solution::findCircleNum(isConnected));
  }
  {
    std::vector<std::vector<int>> isConnected{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    REQUIRE(3 == Solution::findCircleNum(isConnected));
  }
}
