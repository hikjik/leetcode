#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::string> words;
    std::vector<int> groups;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .words{"e", "a", "b"},
          .groups{0, 0, 1},
          .expected{"e", "b"},
      },
      {
          .n = 4,
          .words{"a", "b", "c", "d"},
          .groups{1, 0, 1, 1},
          .expected{"a", "b", "c"},
      },
  };

  for (const auto &[n, words, groups, expected] : test_cases) {
    const auto actual =
        Solution::getWordsInLongestSubsequence(n, words, groups);
    REQUIRE(expected == actual);
  }
}
