#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::longestValidParentheses("(()"));
  REQUIRE(4 == Solution::longestValidParentheses(")()())"));
  REQUIRE(0 == Solution::longestValidParentheses(""));
  REQUIRE(2 == Solution::longestValidParentheses("()(()"));
  REQUIRE(2 == Solution::longestValidParentheses("()"));
}
