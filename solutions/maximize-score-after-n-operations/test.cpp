#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 4, 6, 8};
    REQUIRE(11 == Solution::maxScore(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 4, 5, 6};
    REQUIRE(14 == Solution::maxScore(nums));
  }
}
