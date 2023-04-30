#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> mat{{0, 0}, {0, 1}};
    REQUIRE(3 == Solution::minFlips(mat));
  }
  {
    std::vector<std::vector<int>> mat{{0}};
    REQUIRE(0 == Solution::minFlips(mat));
  }
  {
    std::vector<std::vector<int>> mat{{1, 0, 0}, {1, 0, 0}};
    REQUIRE(-1 == Solution::minFlips(mat));
  }
}
