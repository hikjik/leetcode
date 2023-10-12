#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"a", "b", "ba", "bca", "bda", "bdca"},
          .expected = 4,
      },
      {
          .words{"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"},
          .expected = 5,
      },
      {
          .words{"abcd", "dbqca"},
          .expected = 1,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::longestStrChain(words);
    REQUIRE(expected == actual);
  }
}
