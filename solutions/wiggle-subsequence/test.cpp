#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 7, 4, 9, 2, 5};
    REQUIRE(6 == Solution::wiggleMaxLength(nums));
  }
  {
    std::vector<int> nums{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    REQUIRE(7 == Solution::wiggleMaxLength(nums));
  }
  {
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    REQUIRE(2 == Solution::wiggleMaxLength(nums));
  }
  {
    std::vector<int> nums{0, 0};
    REQUIRE(1 == Solution::wiggleMaxLength(nums));
  }
  {
    std::vector<int> nums{0, 0, 0, 0};
    REQUIRE(1 == Solution::wiggleMaxLength(nums));
  }
}