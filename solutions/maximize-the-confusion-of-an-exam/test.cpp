#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string answerKey;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .answerKey = "TTFF",
          .k = 2,
          .expected = 4,
      },
      {
          .answerKey = "TFFT",
          .k = 1,
          .expected = 3,
      },
      {
          .answerKey = "TTFTTFTT",
          .k = 1,
          .expected = 5,
      },
  };

  for (const auto &[answerKey, k, expected] : test_cases) {
    const auto actual = Solution::maxConsecutiveAnswers(answerKey, k);
    REQUIRE(expected == actual);
  }
}
