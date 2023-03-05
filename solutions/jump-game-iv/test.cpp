#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    REQUIRE(3 == Solution::minJumps(arr));
  }
  {
    std::vector<int> arr{7};
    REQUIRE(0 == Solution::minJumps(arr));
  }
  {
    std::vector<int> arr{7, 6, 9, 6, 9, 6, 9, 7};
    REQUIRE(1 == Solution::minJumps(arr));
  }
}
