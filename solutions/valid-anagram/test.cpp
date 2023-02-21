#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isAnagram("anagram", "nagaram"));
  REQUIRE_FALSE(Solution::isAnagram("rat", "car"));
}
