#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> values{0, 1, 0};
    REQUIRE(1 == Solution::peakIndexInMountainArray(values));
  }
  {
    std::vector<int> values{0, 2, 1, 0};
    REQUIRE(1 == Solution::peakIndexInMountainArray(values));
  }
  {
    std::vector<int> values{0, 10, 5, 2};
    REQUIRE(1 == Solution::peakIndexInMountainArray(values));
  }
}
