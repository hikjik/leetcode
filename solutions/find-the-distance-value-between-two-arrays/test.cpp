#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr1{4, 5, 8};
    std::vector<int> arr2{10, 9, 1, 8};
    int d = 2;
    REQUIRE(2 == Solution::findTheDistanceValue(arr1, arr2, d));
  }
  {
    std::vector<int> arr1{1, 4, 2, 3};
    std::vector<int> arr2{-4, -3, 6, 10, 20, 30};
    int d = 3;
    REQUIRE(2 == Solution::findTheDistanceValue(arr1, arr2, d));
  }
  {
    std::vector<int> arr1{2, 1, 100, 3};
    std::vector<int> arr2{-5, -2, 10, -3, 7};
    int d = 6;
    REQUIRE(1 == Solution::findTheDistanceValue(arr1, arr2, d));
  }
}
