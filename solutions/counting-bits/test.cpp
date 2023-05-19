#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 2;
    std::vector<int> expected{0, 1, 1};
    REQUIRE(expected == Solution::countBits(n));
  }
  {
    int n = 5;
    std::vector<int> expected{0, 1, 1, 2, 1, 2};
    REQUIRE(expected == Solution::countBits(n));
  }
}
