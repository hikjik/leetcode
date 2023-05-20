#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int n = 6;
  std::vector<int> speed{2, 10, 3, 1, 5, 8};
  std::vector<int> efficiency{5, 4, 3, 9, 7, 2};
  REQUIRE(60 == Solution::maxPerformance(n, speed, efficiency, 2));
  REQUIRE(68 == Solution::maxPerformance(n, speed, efficiency, 3));
  REQUIRE(72 == Solution::maxPerformance(n, speed, efficiency, 4));
}
