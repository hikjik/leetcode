#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"bella", "label", "roller"},
          .expected{"e", "l", "l"},
      },
      {
          .words{"cool", "lock", "cook"},
          .expected{"c", "o"},
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::commonChars(words);
    REQUIRE(expected == actual);
  }
}
