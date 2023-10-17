#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"adc", "wzy", "abc"},
          .expected = "abc",
      },
      {
          .words{"aaa", "bob", "ccc", "ddd"},
          .expected = "bob",
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::oddString(words);
    REQUIRE(expected == actual);
  }
}
