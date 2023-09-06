#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> dictionary{"leet", "code", "leetcode"};
    std::string s = "leetscode";
    REQUIRE(1 == Solution::minExtraChar(s, dictionary));
  }
  {
    std::vector<std::string> dictionary{"hello", "world"};
    std::string s = "sayhelloworld";
    REQUIRE(3 == Solution::minExtraChar(s, dictionary));
  }
}
