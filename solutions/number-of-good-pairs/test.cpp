#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 1, 1, 3};
    REQUIRE(4 == Solution::numIdenticalPairs(nums));
  }
  {
    std::vector<int> nums{1, 1, 1, 1};
    REQUIRE(6 == Solution::numIdenticalPairs(nums));
  }
  {
    std::vector<int> nums{1, 2, 3};
    REQUIRE(0 == Solution::numIdenticalPairs(nums));
  }
}
