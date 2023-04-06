#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 7, 1, 6};
    REQUIRE(5 == Solution::minimizeArrayValue(nums));
  }
  {
    std::vector<int> nums{10, 1};
    REQUIRE(10 == Solution::minimizeArrayValue(nums));
  }
  {
    std::vector<int> nums{13, 13, 20, 0, 8, 9, 9};
    REQUIRE(16 == Solution::minimizeArrayValue(nums));
  }
}
