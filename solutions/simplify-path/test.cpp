#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("/home" == Solution::simplifyPath("/home/"));
  REQUIRE("/" == Solution::simplifyPath("/../"));
  REQUIRE("/home/foo" == Solution::simplifyPath("/home//foo/"));
}
