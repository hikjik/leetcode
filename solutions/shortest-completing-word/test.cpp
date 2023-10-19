#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string licensePlate;
    std::vector<std::string> words;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .licensePlate = "1s3 PSt",
          .words{"step", "steps", "stripe", "stepple"},
          .expected = "steps",
      },
      {
          .licensePlate = "1s3 456",
          .words{"looks", "pest", "stew", "show"},
          .expected = "pest",
      },
  };

  for (const auto &[licensePlate, words, expected] : test_cases) {
    const auto actual = Solution::shortestCompletingWord(licensePlate, words);
    REQUIRE(expected == actual);
  }
}
