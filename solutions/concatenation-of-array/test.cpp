#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 1};
    std::vector<int> expected{1, 2, 1, 1, 2, 1};
    REQUIRE(expected == Solution::getConcatenation(nums));
  }
  {
    std::vector<int> nums{1, 3, 2, 1};
    std::vector<int> expected{1, 3, 2, 1, 1, 3, 2, 1};
    REQUIRE(expected == Solution::getConcatenation(nums));
  }
}
