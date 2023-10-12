#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string secret;
    std::string guess;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .secret = "1807",
          .guess = "7810",
          .expected = "1A3B",
      },
      {
          .secret = "1123",
          .guess = "0111",
          .expected = "1A1B",
      },
  };

  for (const auto &[secret, guess, expected] : test_cases) {
    const auto actual = Solution::getHint(secret, guess);
    REQUIRE(expected == actual);
  }
}
