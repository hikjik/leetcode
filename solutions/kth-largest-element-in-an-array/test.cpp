#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> nums{3, 2, 1, 5, 6, 4};
    REQUIRE(5 == Solution::findKthLargest(nums, k));
  }
  {
    int k = 4;
    std::vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    REQUIRE(4 == Solution::findKthLargest(nums, k));
  }
  {
    int k = 1;
    std::vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    REQUIRE(6 == Solution::findKthLargest(nums, k));
  }
}
