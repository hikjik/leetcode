#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "aeiouu",
          .expected = 2,
      },
      {
          .word = "unicornarihan",
          .expected = 0,
      },
      {
          .word = "cuaieuouac",
          .expected = 7,
      },
  };

  for (const auto &[word, expected] : test_cases) {
    const auto actual = Solution::countVowelSubstrings(word);
    REQUIRE(expected == actual);
  }
}
