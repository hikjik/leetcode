#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> expected{0, 1, 2, 4, 8, 3, 5, 6, 7};
    REQUIRE(expected == Solution::sortByBits(arr));
  }
  {
    std::vector<int> arr{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    std::vector<int> expected{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    REQUIRE(expected == Solution::sortByBits(arr));
  }
}
