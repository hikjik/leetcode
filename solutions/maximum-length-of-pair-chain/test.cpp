#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> pairs{{1, 2}, {2, 3}, {3, 4}};
    REQUIRE(2 == Solution::findLongestChain(pairs));
  }
  {
    std::vector<std::vector<int>> pairs{{1, 2}, {7, 8}, {4, 5}};
    REQUIRE(3 == Solution::findLongestChain(pairs));
  }
}
