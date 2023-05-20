#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> ratings{1, 0, 2};
    REQUIRE(5 == Solution::candy(ratings));
  }
  {
    std::vector<int> ratings{1, 2, 2};
    REQUIRE(4 == Solution::candy(ratings));
  }
  {
    std::vector<int> ratings{1, 0, 2, 3, 5, 2, 1};
    REQUIRE(15 == Solution::candy(ratings));
  }
}
