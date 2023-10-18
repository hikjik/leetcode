#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int left;
    int right;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"are", "amy", "u"},
          .left = 0,
          .right = 2,
          .expected = 2,
      },
      {
          .words{"hey", "aeo", "mu", "ooo", "artro"},
          .left = 1,
          .right = 4,
          .expected = 3,
      },
  };

  for (const auto &[words, left, right, expected] : test_cases) {
    const auto actual = Solution::vowelStrings(words, left, right);
    REQUIRE(expected == actual);
  }
}
