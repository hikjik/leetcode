#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int target = 18;
    std::vector<int> arr{3, 4, 5, 6};
    REQUIRE(6 == Solution::findBestValue(arr, target));
  }
  {
    int target = 71237;
    std::vector<int> arr{1547, 83230, 57084, 93444, 70879};
    REQUIRE(17422 == Solution::findBestValue(arr, target));
  }
  {
    int target = 10;
    std::vector<int> arr{4, 9, 3};
    REQUIRE(3 == Solution::findBestValue(arr, target));
  }
  {
    int target = 10;
    std::vector<int> arr{2, 3, 5};
    REQUIRE(5 == Solution::findBestValue(arr, target));
  }
  {
    int target = 56803;
    std::vector<int> arr{60864, 25176, 27249, 21296, 20204};
    REQUIRE(11361 == Solution::findBestValue(arr, target));
  }
}
