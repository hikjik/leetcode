#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3;
    std::vector<std::string> pizza{"A..", "AAA", "..."};
    REQUIRE(3 == Solution::ways(pizza, k));
  }
  {
    int k = 3;
    std::vector<std::string> pizza{"A..", "AA.", "..."};
    REQUIRE(1 == Solution::ways(pizza, k));
  }
  {
    int k = 1;
    std::vector<std::string> pizza{"A..", "A..", "..."};
    REQUIRE(1 == Solution::ways(pizza, k));
  }
}
