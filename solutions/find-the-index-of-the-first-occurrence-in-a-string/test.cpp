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

  for (const auto &[haystack, needle, expected] : test_cases) {
    const auto actual = Solution::strStr(haystack, needle);
    REQUIRE(expected == actual);
  }
}
