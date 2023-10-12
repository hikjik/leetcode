#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int k;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"i", "love", "leetcode", "i", "love", "coding"},
          .k = 2,
          .expected{"i", "love"},
      },
      {
          .words{"the", "day", "is", "sunny", "the", "the", "the", "sunny",
                 "is", "is"},
          .k = 4,
          .expected{"the", "is", "sunny", "day"},
      },
  };

  for (const auto &[words, k, expected] : test_cases) {
    const auto actual = Solution::topKFrequent(words, k);
    REQUIRE(expected == actual);
  }
}
