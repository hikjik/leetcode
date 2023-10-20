#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string pref;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"pay", "attention", "practice", "attend"},
          .pref = "at",
          .expected = 2,
      },
      {
          .words{"leetcode", "win", "loops", "success"},
          .pref = "code",
          .expected = 0,
      },
  };

  for (const auto &[words, pref, expected] : test_cases) {
    const auto actual = Solution::prefixCount(words, pref);
    REQUIRE(expected == actual);
  }
}
