#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string text;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .text = "nlaebolko",
          .expected = 1,
      },
      {
          .text = "loonbalxballpoon",
          .expected = 2,
      },
      {
          .text = "leetcode",
          .expected = 0,
      },
  };

  for (const auto &[text, expected] : test_cases) {
    const auto actual = Solution::maxNumberOfBalloons(text);
    REQUIRE(expected == actual);
  }
}
