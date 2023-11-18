#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"ab", "ba", "abc", "cba"},
          .expected{{1, 0}, {0, 1}, {3, 2}, {2, 3}, {0, 3}, {2, 1}},
      },
      {
          .words{"abcd", "dcba", "lls", "s", "sssll"},
          .expected{{0, 1}, {1, 0}, {3, 2}, {2, 4}},
      },
      {
          .words{"bat", "tab", "cat"},
          .expected{{0, 1}, {1, 0}},
      },
      {
          .words{"a", ""},
          .expected{{0, 1}, {1, 0}},
      },
      {
          .words{"a", "b", "c", "ab", "ac", "aa"},
          .expected{{3, 0}, {1, 3}, {4, 0}, {2, 4}, {5, 0}, {0, 5}},
      },
  };

  SECTION("Hash Table") {
    for (const auto &[words, expected] : test_cases) {
      const auto actual = hash_table::Solution::palindromePairs(words);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Rolling Hash") {
    for (const auto &[words, expected] : test_cases) {
      const auto actual = rolling_hash::Solution::palindromePairs(words);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }

  SECTION("Trie") {
    for (const auto &[words, expected] : test_cases) {
      const auto actual = trie::Solution::palindromePairs(words);
      REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
    }
  }
}
