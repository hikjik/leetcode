#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 4, x = 3;
    std::vector<int> arr{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 4};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
  {
    int k = 4, x = -1;
    std::vector<int> arr{1, 2, 3, 4, 5};
    std::vector<int> expected{1, 2, 3, 4};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
  {
    int k = 4, x = 6;
    std::vector<int> arr{1, 2, 3, 4, 5};
    std::vector<int> expected{2, 3, 4, 5};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
  {
    int k = 1, x = 9;
    std::vector<int> arr{1, 1, 1, 10, 10, 10};
    std::vector<int> expected{10};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
  {
    int k = 2, x = 2;
    std::vector<int> arr{0, 0, 0, 1, 3, 5, 6, 7, 8, 8};
    std::vector<int> expected{1, 3};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
  {
    int k = 7, x = 2;
    std::vector<int> arr{1, 2, 2, 2, 2, 2, 2, 4};
    std::vector<int> expected{1, 2, 2, 2, 2, 2, 2};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
  {
    int k = 6, x = 2;
    std::vector<int> arr{1, 2, 2, 2, 2, 2, 4};
    std::vector<int> expected{1, 2, 2, 2, 2, 2};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
  {
    int k = 7, x = 4;
    std::vector<int> arr{1, 4, 4, 4, 4, 4, 4, 5};
    std::vector<int> expected{4, 4, 4, 4, 4, 4, 5};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
  {
    int k = 6, x = 4;
    std::vector<int> arr{1, 4, 4, 4, 4, 4, 5};
    std::vector<int> expected{4, 4, 4, 4, 4, 5};
    REQUIRE(expected == Solution::findClosestElements(arr, k, x));
  }
}
