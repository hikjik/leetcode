#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string str("a1b2");
    std::vector<std::string> permutations{"a1b2", "a1B2", "A1b2", "A1B2"};
    REQUIRE(permutations == Solution::letterCasePermutation(str));
  }
  {
    std::string str("3z4");
    std::vector<std::string> permutations{"3z4", "3Z4"};
    REQUIRE(permutations == Solution::letterCasePermutation(str));
  }
}
