#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3;
    std::vector<std::string> combinations{"((()))", "(()())", "(())()",
                                          "()(())", "()()()"};
    REQUIRE(combinations == Solution::generateParenthesis(n));
  }
  {
    int n = 1;
    std::vector<std::string> combinations{"()"};
    REQUIRE(combinations == Solution::generateParenthesis(n));
  }
}
