#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"cd", "ac", "dc", "ca", "zz"},
          .expected = 2,
      },
      {
          .words{"ab", "ba", "cc"},
          .expected = 1,
      },
      {
          .words{"aa", "ab"},
          .expected = 0,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::maximumNumberOfStringPairs(words);
    REQUIRE(expected == actual);
  }
}
