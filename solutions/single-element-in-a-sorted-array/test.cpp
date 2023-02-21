#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
    REQUIRE(2 == Solution::singleNonDuplicate(nums));
  }
  {
    std::vector<int> nums{3, 3, 7, 7, 10, 11, 11};
    REQUIRE(10 == Solution::singleNonDuplicate(nums));
  }
}
