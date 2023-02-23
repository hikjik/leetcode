#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 3, 4, 2, 2};
    REQUIRE(2 == Solution::findDuplicate(nums));
  }
  {
    std::vector<int> nums{3, 1, 3, 4, 2};
    REQUIRE(3 == Solution::findDuplicate(nums));
  }
  {
    std::vector<int> nums{2, 2, 2, 2, 2};
    REQUIRE(2 == Solution::findDuplicate(nums));
  }
}
