#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> weights{1, 3, 5, 1};
    REQUIRE(4 == Solution::putMarbles(weights, k));
  }
  {
    int k = 2;
    std::vector<int> weights{1, 3};
    REQUIRE(0 == Solution::putMarbles(weights, k));
  }
}
