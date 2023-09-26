#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 21, 5};
    REQUIRE(4 == Solution::minimumReplacement(nums));
  }
  {
    std::vector<int> nums{3, 9, 3};
    REQUIRE(2 == Solution::minimumReplacement(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 4, 5};
    REQUIRE(0 == Solution::minimumReplacement(nums));
  }
}
