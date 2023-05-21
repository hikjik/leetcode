#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{0, 1, 2, 4, 5, 7};
    std::vector<std::string> expected{"0->2", "4->5", "7"};
    REQUIRE(expected == Solution::summaryRanges(nums));
  }
  {
    std::vector<int> nums{0, 2, 3, 4, 6, 8, 9};
    std::vector<std::string> expected{"0", "2->4", "6", "8->9"};
    REQUIRE(expected == Solution::summaryRanges(nums));
  }
}
