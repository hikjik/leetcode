#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string target;
    int startIndex;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"hello", "i", "am", "leetcode", "hello"},
          .target = "hello",
          .startIndex = 1,
          .expected = 1,
      },
      {
          .words{"a", "b", "leetcode"},
          .target = "leetcode",
          .startIndex = 0,
          .expected = 1,
      },
      {
          .words{"i", "eat", "leetcode"},
          .target = "ate",
          .startIndex = 0,
          .expected = -1,
      },
  };

  for (const auto &[words, target, startIndex, expected] : test_cases) {
    const auto actual = Solution::closetTarget(words, target, startIndex);
    REQUIRE(expected == actual);
  }
}
