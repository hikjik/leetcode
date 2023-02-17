#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 7, 3, 6, 5, 6};
    REQUIRE(3 == Solution::pivotIndex(nums));
  }

  {
    std::vector<int> nums{1, 2, 3};
    REQUIRE(-1 == Solution::pivotIndex(nums));
  }

  {
    std::vector<int> nums{2, 1, -1};
    REQUIRE(0 == Solution::pivotIndex(nums));
  }
}
