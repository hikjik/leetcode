#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> stones{0, 1, 3, 5, 6, 8, 12, 17};
    REQUIRE(Solution::canCross(stones));
  }
  {
    std::vector<int> stones{0, 1, 2, 3, 4, 8, 9, 11};
    REQUIRE_FALSE(Solution::canCross(stones));
  }
  {
    std::vector<int> stones{0, 1, 3, 6, 10};
    REQUIRE(Solution::canCross(stones));
  }
}
