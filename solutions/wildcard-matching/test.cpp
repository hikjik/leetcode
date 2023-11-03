#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string p;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbabab"
               "aab"
               "bbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbba"
               "aab"
               "bbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaa"
               "bab"
               "aaaabb",
          .p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*"
               "b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb",
          .expected = false,
      },
      {
          .s = "aa",
          .p = "a",
          .expected = false,
      },
      {
          .s = "aa",
          .p = "*",
          .expected = true,
      },
      {
          .s = "cb",
          .p = "?a",
          .expected = false,
      },
  };

  SECTION("Memoization") {
    for (const auto &[s, p, expected] : test_cases) {
      const auto actual = memoization::Solution::isMatch(s, p);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Dynamic Programming") {
    for (const auto &[s, p, expected] : test_cases) {
      const auto actual = dp::Solution::isMatch(s, p);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Greedy") {
    for (const auto &[s, p, expected] : test_cases) {
      const auto actual = greedy::Solution::isMatch(s, p);
      REQUIRE(expected == actual);
    }
  }
}
