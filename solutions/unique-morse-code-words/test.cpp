#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"gin", "zen", "gig", "msg"},
          .expected = 2,
      },
      {
          .words{"a"},
          .expected = 1,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::uniqueMorseRepresentations(words);
    REQUIRE(expected == actual);
  }
}
