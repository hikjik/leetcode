#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{1, 2, 2, 1, 1, 3};
    REQUIRE(Solution::uniqueOccurrences(arr));
  }
  {
    std::vector<int> arr{1, 2};
    REQUIRE_FALSE(Solution::uniqueOccurrences(arr));
  }
  {
    std::vector<int> arr{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    REQUIRE(Solution::uniqueOccurrences(arr));
  }
}
