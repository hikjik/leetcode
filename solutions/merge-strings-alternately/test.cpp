#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("apbqcr" == Solution::mergeAlternately("abc", "pqr"));
  REQUIRE("apbqrs" == Solution::mergeAlternately("ab", "pqrs"));
  REQUIRE("apbqcd" == Solution::mergeAlternately("abcd", "pq"));
}
