#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words1;
    std::vector<std::string> words2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words1{"leetcode", "is", "amazing", "as", "is"},
          .words2{"amazing", "leetcode", "is"},
          .expected = 2,
      },
      {
          .words1{"b", "bb", "bbb"},
          .words2{"a", "aa", "aaa"},
          .expected = 0,
      },
      {
          .words1{"a", "ab"},
          .words2{"a", "a", "a", "ab"},
          .expected = 1,
      },
  };

  for (const auto &[words1, words2, expected] : test_cases) {
    const auto actual = Solution::countWords(words1, words2);
    REQUIRE(expected == actual);
  }
}
