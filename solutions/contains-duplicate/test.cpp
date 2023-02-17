#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 1};
    REQUIRE(true == Solution::containsDuplicate(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 4};
    REQUIRE(false == Solution::containsDuplicate(nums));
  }
  {
    std::vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    REQUIRE(true == Solution::containsDuplicate(nums));
  }
}
