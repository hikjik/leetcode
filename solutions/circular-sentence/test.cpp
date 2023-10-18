#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string sentence;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sentence = "leetcode exercises sound delightful",
          .expected = true,
      },
      {
          .sentence = "eetcode",
          .expected = true,
      },
      {
          .sentence = "Leetcode is cool",
          .expected = false,
      },
  };

  for (const auto &[sentence, expected] : test_cases) {
    const auto actual = Solution::isCircularSentence(sentence);
    REQUIRE(expected == actual);
  }
}
