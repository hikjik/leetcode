#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{2, 3, 4, 7, 11};
    REQUIRE(9 == Solution::findKthPositive(arr, 5));
  }
  {
    std::vector<int> arr{1, 2, 3, 4};
    REQUIRE(6 == Solution::findKthPositive(arr, 2));
  }
}
