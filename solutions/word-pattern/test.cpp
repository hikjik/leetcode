#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string pattern;
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .pattern = "abba",
          .s = "dog cat cat dog",
          .expected = true,
      },
      {
          .pattern = "abba",
          .s = "dog cat cat fish",
          .expected = false,
      },
      {
          .pattern = "aaaa",
          .s = "dog cat cat dog",
          .expected = false,
      },
  };

  for (const auto &[pattern, s, expected] : test_cases) {
    const auto actual = Solution::wordPattern(pattern, s);
    REQUIRE(expected == actual);
  }
}
