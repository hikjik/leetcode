#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 4;
    std::vector<int> rolls{4, 2, 1, 2, 3, 3, 2, 4, 1};
    REQUIRE(3 == Solution::shortestSequence(rolls, k));
  }
  {
    int k = 2;
    std::vector<int> rolls{1, 1, 2, 2};
    REQUIRE(2 == Solution::shortestSequence(rolls, k));
  }
  {
    int k = 4;
    std::vector<int> rolls{1, 1, 3, 2, 2, 2, 3, 3};
    REQUIRE(1 == Solution::shortestSequence(rolls, k));
  }
}
