#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string order;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"hello", "leetcode"},
          .order = "hlabcdefgijkmnopqrstuvwxyz",
          .expected = true,
      },
      {
          .words{"word", "world", "row"},
          .order = "worldabcefghijkmnpqstuvxyz",
          .expected = false,
      },
      {
          .words{"apple", "app"},
          .order = "abcdefghijklmnopqrstuvwxyz",
          .expected = false,
      },
  };

  for (const auto &[words, order, expected] : test_cases) {
    const auto actual = Solution::isAlienSorted(words, order);
    REQUIRE(expected == actual);
  }
}
