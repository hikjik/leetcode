#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"abc", "car", "ada", "racecar", "cool"},
          .expected = "ada",
      },
      {
          .words{"notapalindrome", "racecar"},
          .expected = "racecar",
      },
      {
          .words{"def", "ghi"},
          .expected = "",
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::firstPalindrome(words);
    REQUIRE(expected == actual);
  }
}
