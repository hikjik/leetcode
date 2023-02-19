#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    auto str = "Let's take LeetCode contest";
    auto expected = "s'teL ekat edoCteeL tsetnoc";
    REQUIRE(expected == Solution::reverseWords(str));
  }
  {
    auto str = "God Ding";
    auto expected = "doG gniD";
    REQUIRE(expected == Solution::reverseWords(str));
  }
  {
    auto str = "God";
    auto expected = "doG";
    REQUIRE(expected == Solution::reverseWords(str));
  }
}
