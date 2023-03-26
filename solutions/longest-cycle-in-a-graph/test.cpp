#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> edges{3, 3, 4, 2, 3};
    REQUIRE(3 == Solution::longestCycle(edges));
  }
  {
    std::vector<int> edges{2, -1, 3, 1};
    REQUIRE(-1 == Solution::longestCycle(edges));
  }
}
