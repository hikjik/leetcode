#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{9};
    int max_operations = 2;
    REQUIRE(3 == Solution::minimumSize(nums, max_operations));
  }
  {
    std::vector<int> nums{2, 4, 8, 2};
    int max_operations = 4;
    REQUIRE(2 == Solution::minimumSize(nums, max_operations));
  }
}
