#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{1, 2, 3, 4};
    REQUIRE("23:41" == Solution::largestTimeFromDigits(arr));
  }
  {
    std::vector<int> arr{5, 5, 5, 5};
    REQUIRE("" == Solution::largestTimeFromDigits(arr));
  }
  {
    std::vector<int> arr{0, 0, 0, 0};
    REQUIRE("00:00" == Solution::largestTimeFromDigits(arr));
  }
  {
    std::vector<int> arr{4, 1, 0, 0};
    REQUIRE("14:00" == Solution::largestTimeFromDigits(arr));
  }
}
