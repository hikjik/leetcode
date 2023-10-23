#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "a123bc34d8ef34",
          .expected = 3,
      },
      {
          .word = "leet1234code234",
          .expected = 2,
      },
      {
          .word = "a1b01c001",
          .expected = 1,
      },
      {
          .word = "a0b00c000",
          .expected = 1,
      },
  };

  for (const auto &[word, expected] : test_cases) {
    const auto actual = Solution::numDifferentIntegers(word);
    REQUIRE(expected == actual);
  }
}
