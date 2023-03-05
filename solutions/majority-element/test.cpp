#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 2, 3};
    REQUIRE(3 == Solution::majorityElement(nums));
  }
  {
    std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    REQUIRE(2 == Solution::majorityElement(nums));
  }
}
