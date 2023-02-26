#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> combinations{{1, 2}, {1, 3}, {1, 4},
                                               {2, 3}, {2, 4}, {3, 4}};
    REQUIRE(combinations == Solution::combine(4, 2));
  }
  {
    std::vector<std::vector<int>> combinations{{1}};
    REQUIRE(combinations == Solution::combine(1, 1));
  }
}
