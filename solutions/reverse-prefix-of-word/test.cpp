#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    char ch;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "abcdefd",
          .ch = 'd',
          .expected = "dcbaefd",
      },
      {
          .word = "xyxzxe",
          .ch = 'z',
          .expected = "zxyxxe",
      },
      {
          .word = "abcd",
          .ch = 'z',
          .expected = "abcd",
      },
  };

  for (const auto &[word, ch, expected] : test_cases) {
    const auto actual = Solution::reversePrefix(word, ch);
    REQUIRE(expected == actual);
  }
}
