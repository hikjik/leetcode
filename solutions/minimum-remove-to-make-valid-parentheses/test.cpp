#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("lee(t(c)o)de" == Solution::minRemoveToMakeValid("lee(t(c)o)de)"));
  REQUIRE("ab(c)d" == Solution::minRemoveToMakeValid("a)b(c)d"));
  REQUIRE("" == Solution::minRemoveToMakeValid("))(("));
  REQUIRE("((a))" == Solution::minRemoveToMakeValid("(((a))"));
  REQUIRE("((a))" == Solution::minRemoveToMakeValid("((a)))"));
}
