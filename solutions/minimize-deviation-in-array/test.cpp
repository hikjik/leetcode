#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 4};
    REQUIRE(1 == Solution::minimumDeviation(nums));
  }
  {
    std::vector<int> nums{4, 1, 5, 20, 3};
    REQUIRE(3 == Solution::minimumDeviation(nums));
  }
  {
    std::vector<int> nums{2, 10, 8};
    REQUIRE(3 == Solution::minimumDeviation(nums));
  }
  {
    std::vector<int> nums{3, 5};
    REQUIRE(1 == Solution::minimumDeviation(nums));
  }
}
