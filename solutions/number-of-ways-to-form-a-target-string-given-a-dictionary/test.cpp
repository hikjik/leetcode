#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string target = "aba";
    std::vector<std::string> words{"acca", "bbbb", "caca"};
    REQUIRE(6 == Solution::numWays(words, target));
  }
  {
    std::string target = "bab";
    std::vector<std::string> words{"abba", "baab"};
    REQUIRE(4 == Solution::numWays(words, target));
  }
}
