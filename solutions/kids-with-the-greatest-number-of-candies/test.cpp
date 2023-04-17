#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    const int extra_candies = 3;
    std::vector<int> candies{2, 3, 5, 1, 3};
    std::vector<bool> expected{true, true, true, false, true};
    REQUIRE(expected == Solution::kidsWithCandies(candies, extra_candies));
  }
  {
    const int extra_candies = 1;
    std::vector<int> candies{4, 2, 1, 1, 2};
    std::vector<bool> expected{true, false, false, false, false};
    REQUIRE(expected == Solution::kidsWithCandies(candies, extra_candies));
  }
  {
    const int extra_candies = 10;
    std::vector<int> candies{12, 1, 12};
    std::vector<bool> expected{true, false, true};
    REQUIRE(expected == Solution::kidsWithCandies(candies, extra_candies));
  }
}
