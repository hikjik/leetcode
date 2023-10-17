#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "a",
          .expected = true,
      },
      {
          .word = "bac",
          .expected = true,
      },
      {
          .word = "aaaa",
          .expected = true,
      },
      {
          .word = "abcc",
          .expected = true,
      },
      {
          .word = "aazz",
          .expected = false,
      },
  };

  for (const auto &[word, expected] : test_cases) {
    const auto actual = Solution::equalFrequency(word);
    REQUIRE(expected == actual);
  }
}
