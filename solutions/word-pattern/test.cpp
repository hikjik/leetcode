#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::wordPattern("abba", "dog cat cat dog"));
  REQUIRE_FALSE(Solution::wordPattern("abba", "dog cat cat fish"));
  REQUIRE_FALSE(Solution::wordPattern("aaaa", "dog cat cat dog"));

  REQUIRE_FALSE(Solution::wordPattern("abb", "dog cat cat dog"));
  REQUIRE_FALSE(Solution::wordPattern("abba", "dog cat cat"));

  REQUIRE_FALSE(Solution::wordPattern("abba", "dog dog dog dog"));
}
