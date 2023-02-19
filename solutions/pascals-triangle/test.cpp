#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> expected{
        {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    REQUIRE(expected == Solution::generate(5));
  }
  {
    std::vector<std::vector<int>> expected{{1}};
    REQUIRE(expected == Solution::generate(1));
  }
  {
    std::vector<std::vector<int>> expected{{1}, {1, 1}};
    REQUIRE(expected == Solution::generate(2));
  }
}
