#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "abcde",
          .expected = 5,
      },
      {
          .word = "xycdefghij",
          .expected = 12,
      },
  };

  for (const auto &[word, expected] : test_cases) {
    const auto actual = Solution::minimumPushes(word);
    REQUIRE(expected == actual);
  }
}
