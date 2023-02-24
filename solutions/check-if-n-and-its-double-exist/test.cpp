#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> arr{10, 2, 5, 3};
    REQUIRE(Solution::checkIfExist(arr));
  }
  {
    std::vector<int> arr{3, 1, 7, 11};
    REQUIRE_FALSE(Solution::checkIfExist(arr));
  }
}
