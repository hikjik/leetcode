#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> test{1, 2, 3};
    std::vector<int> expected{1, 2, 4};
    REQUIRE(expected == Solution::plusOne(test));
  }
  {
    std::vector<int> test{4, 3, 2, 1};
    std::vector<int> expected{4, 3, 2, 2};
    REQUIRE(expected == Solution::plusOne(test));
  }
  {
    std::vector<int> test{9};
    std::vector<int> expected{1, 0};
    REQUIRE(expected == Solution::plusOne(test));
  }
}
