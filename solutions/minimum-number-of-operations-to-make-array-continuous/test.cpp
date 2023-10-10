#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{4, 2, 5, 3};
    REQUIRE(0 == Solution::minOperations(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 5, 6};
    REQUIRE(1 == Solution::minOperations(nums));
  }
  {
    std::vector<int> nums{1, 10, 100, 1000};
    REQUIRE(3 == Solution::minOperations(nums));
  }
}
