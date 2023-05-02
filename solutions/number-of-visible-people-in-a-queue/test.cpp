#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> heights{10, 6, 8, 5, 11, 9};
    std::vector<int> expected{3, 1, 2, 1, 1, 0};
    REQUIRE(expected == Solution::canSeePersonsCount(heights));
  }
  {
    std::vector<int> heights{5, 1, 2, 3, 10};
    std::vector<int> expected{4, 1, 1, 1, 0};
    REQUIRE(expected == Solution::canSeePersonsCount(heights));
  }
}
