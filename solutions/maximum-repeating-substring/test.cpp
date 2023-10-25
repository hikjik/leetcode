#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string sequence;
    std::string word;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sequence = "ababc",
          .word = "ab",
          .expected = 2,
      },
      {
          .sequence = "ababc",
          .word = "ba",
          .expected = 1,
      },
      {
          .sequence = "ababc",
          .word = "ac",
          .expected = 0,
      },
  };

  for (const auto &[sequence, word, expected] : test_cases) {
    const auto actual = Solution::maxRepeating(sequence, word);
    REQUIRE(expected == actual);
  }
}
