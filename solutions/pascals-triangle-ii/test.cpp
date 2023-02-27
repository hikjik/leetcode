#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> expected{1, 3, 3, 1};
    REQUIRE(expected == Solution::getRow(3));
  }
  {
    std::vector<int> expected{1, 1};
    REQUIRE(expected == Solution::getRow(1));
  }
  {
    std::vector<int> expected{1};
    REQUIRE(expected == Solution::getRow(0));
  }
}
