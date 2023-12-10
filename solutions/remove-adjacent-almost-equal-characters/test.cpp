#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "aaaaa",
          .expected = 2,
      },
      {
          .word = "abddez",
          .expected = 2,
      },
      {
          .word = "zyxyxyz",
          .expected = 3,
      },
  };

  for (const auto &[word, expected] : test_cases) {
    const auto actual = Solution::removeAlmostEqualCharacters(word);
    REQUIRE(expected == actual);
  }
}
