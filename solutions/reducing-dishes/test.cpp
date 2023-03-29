#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> satisfaction{-1, -8, 0, 5, -9};
    REQUIRE(14 == Solution::maxSatisfaction(satisfaction));
  }
  {
    std::vector<int> satisfaction{4, 3, 2};
    REQUIRE(20 == Solution::maxSatisfaction(satisfaction));
  }
  {
    std::vector<int> satisfaction{-1, -4, -5};
    REQUIRE(0 == Solution::maxSatisfaction(satisfaction));
  }
}
