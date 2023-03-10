#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 2, 3, 4};
    REQUIRE(3 == Solution::triangleNumber(nums));
  }
  {
    std::vector<int> nums{4, 2, 3, 4};
    REQUIRE(4 == Solution::triangleNumber(nums));
  }
  {
    std::vector<int> nums{7, 0, 0, 0};
    REQUIRE(0 == Solution::triangleNumber(nums));
  }
}
