#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int m = 1;
    std::vector<int> arr{3, 5, 1, 2, 4};
    REQUIRE(4 == Solution::findLatestStep(arr, m));
  }
  {
    int m = 2;
    std::vector<int> arr{3, 5, 1, 2, 4};
    REQUIRE(-1 == Solution::findLatestStep(arr, m));
  }
  {
    int m = 1;
    std::vector<int> arr{1};
    REQUIRE(1 == Solution::findLatestStep(arr, m));
  }
}
