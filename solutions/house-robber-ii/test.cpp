#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 3, 2};
    REQUIRE(3 == Solution::rob(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 1};
    REQUIRE(4 == Solution::rob(nums));
  }
  {
    std::vector<int> nums{1, 2, 3};
    REQUIRE(3 == Solution::rob(nums));
  }
  {
    std::vector<int> nums{1, 2};
    REQUIRE(2 == Solution::rob(nums));
  }
  {
    std::vector<int> nums{1};
    REQUIRE(1 == Solution::rob(nums));
  }
}
