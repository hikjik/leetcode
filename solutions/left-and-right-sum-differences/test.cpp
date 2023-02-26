#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{10, 4, 8, 3};
    std::vector<int> diff{15, 1, 11, 22};
    REQUIRE(diff == Solution::leftRigthDifference(nums));
  }
  {
    std::vector<int> nums{1};
    std::vector<int> diff{0};
    REQUIRE(diff == Solution::leftRigthDifference(nums));
  }
}
