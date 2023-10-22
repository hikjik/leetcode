#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"abc", "aabc", "bc"},
          .expected = true,
      },
      {
          .words{"ab", "a"},
          .expected = false,
      },
      {
          .words{"abbaa"},
          .expected = true,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::makeEqual(words);
    REQUIRE(expected == actual);
  }
}
