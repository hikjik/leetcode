#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 1, 4, 2, 3};
    const int x = 5;
    REQUIRE(2 == Solution::minOperations(nums, x));
  }
  {
    std::vector<int> nums{5, 6, 7, 8, 9};
    const int x = 4;
    REQUIRE(-1 == Solution::minOperations(nums, x));
  }
  {
    std::vector<int> nums{3, 2, 20, 1, 1, 3};
    const int x = 10;
    REQUIRE(5 == Solution::minOperations(nums, x));
  }
  {
    std::vector<int> nums{1, 2, 3, 4};
    const int x = 10;
    REQUIRE(4 == Solution::minOperations(nums, x));
  }
}
