#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> stones{2, 7, 4, 1, 8, 1};
    REQUIRE(1 == Solution::lastStoneWeight(stones));
  }
  {
    std::vector<int> stones{1};
    REQUIRE(1 == Solution::lastStoneWeight(stones));
  }
}
