#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{4, 2, 3, 0, 3, 1, 2};
    int start = 5;
    REQUIRE(Solution::canReach(arr, start));
  }
  {
    std::vector<int> arr{4, 2, 3, 0, 3, 1, 2};
    int start = 0;
    REQUIRE(Solution::canReach(arr, start));
  }
  {
    std::vector<int> arr{3, 0, 2, 1, 2};
    int start = 2;
    REQUIRE_FALSE(Solution::canReach(arr, start));
  }
}
