#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int difference = 1;
    std::vector<int> arr{1, 2, 3, 4};
    REQUIRE(4 == Solution::longestSubsequence(arr, difference));
  }
  {
    int difference = 1;
    std::vector<int> arr{1, 3, 5, 7};
    REQUIRE(1 == Solution::longestSubsequence(arr, difference));
  }
  {
    int difference = -2;
    std::vector<int> arr{1, 5, 7, 8, 5, 3, 4, 2, 1};
    REQUIRE(4 == Solution::longestSubsequence(arr, difference));
  }
}
