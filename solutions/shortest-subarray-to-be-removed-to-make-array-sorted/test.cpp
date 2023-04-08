#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{1, 2, 3, 10, 4, 2, 3, 5};
    REQUIRE(3 == Solution::findLengthOfShortestSubarray(arr));
  }
  {
    std::vector<int> arr{5, 4, 3, 2, 1};
    REQUIRE(4 == Solution::findLengthOfShortestSubarray(arr));
  }
  {
    std::vector<int> arr{1, 2, 3};
    REQUIRE(0 == Solution::findLengthOfShortestSubarray(arr));
  }
  {
    std::vector<int> arr{1, 2, 3, 10, 0, 7, 8, 9};
    REQUIRE(2 == Solution::findLengthOfShortestSubarray(arr));
  }
}
