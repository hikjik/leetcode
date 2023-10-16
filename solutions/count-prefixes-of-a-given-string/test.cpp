#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"a", "b", "c", "ab", "bc", "abc"},
          .s = "abc",
          .expected = 3,
      },
      {
          .words{"a", "a"},
          .s = "aa",
          .expected = 2,
      },
  };

  for (const auto &[words, s, expected] : test_cases) {
    const auto actual = Solution::countPrefixes(words, s);
    REQUIRE(expected == actual);
  }
}
