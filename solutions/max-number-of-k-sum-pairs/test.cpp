#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 5;
    std::vector<int> nums{1, 2, 3, 4};
    REQUIRE(2 == Solution::maxOperations(nums, k));
  }
  {
    int k = 6;
    std::vector<int> nums{3, 1, 3, 4, 3};
    REQUIRE(1 == Solution::maxOperations(nums, k));
  }
}
