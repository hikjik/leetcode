#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> expected{5, 6, 7, 1, 2, 3, 4};
    Solution::rotate(values, 3);
    REQUIRE(expected == values);
  }
  {
    std::vector<int> values{-1, -100, 3, 99};
    std::vector<int> expected{3, 99, -1, -100};
    Solution::rotate(values, 2);
    REQUIRE(expected == values);
  }
}
