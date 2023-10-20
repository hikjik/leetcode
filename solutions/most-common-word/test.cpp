#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string paragraph;
    std::vector<std::string> banned;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .paragraph =
              "Bob hit a ball, the hit BALL flew far after it was hit.",
          .banned{"hit"},
          .expected = "ball",
      },
      {
          .paragraph = "a.",
          .banned{},
          .expected = "a",
      },
  };

  for (const auto &[paragraph, banned, expected] : test_cases) {
    const auto actual = Solution::mostCommonWord(paragraph, banned);
    REQUIRE(expected == actual);
  }
}
