#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 5};
    REQUIRE(2 == Solution::specialArray(nums));
  }
  {
    std::vector<int> nums{0, 0};
    REQUIRE(-1 == Solution::specialArray(nums));
  }
  {
    std::vector<int> nums{0, 4, 3, 0, 4};
    REQUIRE(3 == Solution::specialArray(nums));
  }
}
