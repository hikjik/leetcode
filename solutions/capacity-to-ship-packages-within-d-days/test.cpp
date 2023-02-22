#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    REQUIRE(15 == Solution::shipWithinDays(weights, 5));
  }
  {
    std::vector<int> weights{3, 2, 2, 4, 1, 4};
    REQUIRE(6 == Solution::shipWithinDays(weights, 3));
  }
  {
    std::vector<int> weights{1, 2, 3, 1, 1};
    REQUIRE(3 == Solution::shipWithinDays(weights, 4));
  }
}
