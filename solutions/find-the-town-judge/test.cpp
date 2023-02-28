#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 2;
    std::vector<std::vector<int>> trust{{1, 2}};
    REQUIRE(2 == Solution::findJudge(n, trust));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> trust{{1, 3}, {2, 3}};
    REQUIRE(3 == Solution::findJudge(n, trust));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> trust{{1, 3}, {2, 3}, {3, 1}};
    REQUIRE(-1 == Solution::findJudge(n, trust));
  }
}
