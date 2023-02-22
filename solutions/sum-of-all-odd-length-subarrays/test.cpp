#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{1, 4, 2, 5, 3};
    REQUIRE(58 == Solution::sumOddLengthSubarrays(arr));
  }
  {
    std::vector<int> arr{1, 2};
    REQUIRE(3 == Solution::sumOddLengthSubarrays(arr));
  }
  {
    std::vector<int> arr{10, 11, 12};
    REQUIRE(66 == Solution::sumOddLengthSubarrays(arr));
  }
}
