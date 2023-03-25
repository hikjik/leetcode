#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string digits = "23";
    std::vector<std::string> combinations{"ad", "ae", "af", "bd", "be",
                                          "bf", "cd", "ce", "cf"};
    REQUIRE(combinations == Solution::letterCombinations(digits));
  }
  {
    std::string digits = "";
    std::vector<std::string> combinations;
    REQUIRE(combinations == Solution::letterCombinations(digits));
  }
  {
    std::string digits = "2";
    std::vector<std::string> combinations{"a", "b", "c"};
    REQUIRE(combinations == Solution::letterCombinations(digits));
  }
}
