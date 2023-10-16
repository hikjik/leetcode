#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    char letter;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "foobar",
          .letter = 'o',
          .expected = 33,
      },
      {
          .s = "jjjj",
          .letter = 'k',
          .expected = 0,
      },
  };

  for (const auto &[s, letter, expected] : test_cases) {
    const auto actual = Solution::percentageLetter(s, letter);
    REQUIRE(expected == actual);
  }
}
