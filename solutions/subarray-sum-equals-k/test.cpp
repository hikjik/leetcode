#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 1, 1};
    int k = 2;
    REQUIRE(2 == Solution::subarraySum(nums, k));
  }
  {
    std::vector<int> nums{1, 2, 3};
    int k = 3;
    REQUIRE(2 == Solution::subarraySum(nums, k));
  }
}
