#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 1, 1};
    REQUIRE(1 == Solution::waysToSplit(nums));
  }
  {
    std::vector<int> nums{1, 2, 2, 2, 5, 0};
    REQUIRE(3 == Solution::waysToSplit(nums));
  }
  {
    std::vector<int> nums{3, 2, 1};
    REQUIRE(0 == Solution::waysToSplit(nums));
  }
  {
    std::vector<int> nums{2, 3, 5, 10};
    REQUIRE(3 == Solution::waysToSplit(nums));
  }
  {
    std::vector<int> nums(1e5, 0);
    REQUIRE(999849973 == Solution::waysToSplit(nums));
  }
}
