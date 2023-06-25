#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{3, 6, 9, 12};
    REQUIRE(4 == Solution::longestArithSeqLength(nums));
  }
  {
    std::vector<int> nums{9, 4, 7, 2, 10};
    REQUIRE(3 == Solution::longestArithSeqLength(nums));
  }
  {
    std::vector<int> nums{20, 1, 15, 3, 10, 5, 8};
    REQUIRE(4 == Solution::longestArithSeqLength(nums));
  }
}
