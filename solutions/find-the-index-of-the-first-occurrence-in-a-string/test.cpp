#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string haystack;
    std::string needle;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .haystack = "sadbutsad",
          .needle = "sad",
          .expected = 0,
      },
      {
          .haystack = "leetcode",
          .needle = "leeto",
          .expected = -1,
      },
  };

  SECTION("Naive") {
    for (const auto &[haystack, needle, expected] : test_cases) {
      const auto actual = naive::Solution::strStr(haystack, needle);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Boyer-Moore Algorithm") {
    for (const auto &[haystack, needle, expected] : test_cases) {
      const auto actual = boyer_moore::Solution::strStr(haystack, needle);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Boyer-Moore-Horspool Algorithm") {
    for (const auto &[haystack, needle, expected] : test_cases) {
      const auto actual =
          boyer_moore_horspool::Solution::strStr(haystack, needle);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Knuth-Morris-Pratt Algorithm") {
    for (const auto &[haystack, needle, expected] : test_cases) {
      const auto actual =
          knuth_morris_pratt::Solution::strStr(haystack, needle);
      REQUIRE(expected == actual);
    }
  }
}
