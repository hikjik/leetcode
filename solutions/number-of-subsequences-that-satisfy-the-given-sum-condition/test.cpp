#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int target = 9;
    std::vector<int> nums{3, 5, 6, 7};
    REQUIRE(4 == Solution::numSubseq(nums, target));
  }
  {
    int target = 10;
    std::vector<int> nums{3, 3, 6, 8};
    REQUIRE(6 == Solution::numSubseq(nums, target));
  }
  {
    int target = 12;
    std::vector<int> nums{2, 3, 3, 4, 6, 7};
    REQUIRE(61 == Solution::numSubseq(nums, target));
  }
}
