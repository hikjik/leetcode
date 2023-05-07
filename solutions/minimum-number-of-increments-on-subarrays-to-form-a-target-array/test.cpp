#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> target{1, 2, 3, 2, 1};
    REQUIRE(3 == Solution::minNumberOperations(target));
  }
  {
    std::vector<int> target{3, 1, 1, 2};
    REQUIRE(4 == Solution::minNumberOperations(target));
  }
  {
    std::vector<int> target{3, 1, 5, 4, 2};
    REQUIRE(7 == Solution::minNumberOperations(target));
  }
}
