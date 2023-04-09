#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string colors = "abaca";
    std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    REQUIRE(3 == Solution::largestPathValue(colors, edges));
  }
  {
    std::string colors = "a";
    std::vector<std::vector<int>> edges{{0, 0}};
    REQUIRE(-1 == Solution::largestPathValue(colors, edges));
  }
}
