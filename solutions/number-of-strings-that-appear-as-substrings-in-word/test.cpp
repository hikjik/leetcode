#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> patterns;
    std::string word;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .patterns{"a", "abc", "bc", "d"},
          .word = "abc",
          .expected = 3,
      },
      {
          .patterns{"a", "b", "c"},
          .word = "aaaaabbbbb",
          .expected = 2,
      },
      {
          .patterns{"a", "a", "a"},
          .word = "ab",
          .expected = 3,
      },
  };

  for (const auto &[patterns, word, expected] : test_cases) {
    const auto actual = Solution::numOfStrings(patterns, word);
    REQUIRE(expected == actual);
  }
}
