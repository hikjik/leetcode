#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 5, 2};
    REQUIRE_FALSE(Solution::PredictTheWinner(nums));
  }
  {
    std::vector<int> nums{1, 5, 233, 7};
    REQUIRE(Solution::PredictTheWinner(nums));
  }
}
