#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "Hello how are you Contestant",
          .k = 4,
          .expected = "Hello how are you",
      },
      {
          .s = "What is the solution to this problem",
          .k = 4,
          .expected = "What is the solution",
      },
      {
          .s = "chopper is not a tanuki",
          .k = 5,
          .expected = "chopper is not a tanuki",
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::truncateSentence(s, k);
    REQUIRE(expected == actual);
  }
}
