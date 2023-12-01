#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> word1;
    std::vector<std::string> word2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word1{"ab", "c"},
          .word2{"a", "bc"},
          .expected = true,
      },
      {
          .word1{"a", "cb"},
          .word2{"ab", "c"},
          .expected = false,
      },
      {
          .word1{"abc", "d", "defg"},
          .word2{"abcddefg"},
          .expected = true,
      },
  };

  SECTION("Extra Space") {
    for (const auto &[word1, word2, expected] : test_cases) {
      const auto actual =
          extra_space::Solution::arrayStringsAreEqual(word1, word2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Iterator") {
    for (const auto &[word1, word2, expected] : test_cases) {
      const auto actual =
          flatten_iterator::Solution::arrayStringsAreEqual(word1, word2);
      REQUIRE(expected == actual);
    }
  }
}
