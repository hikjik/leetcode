#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> tokens;
    int power;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .tokens{100},
          .power = 50,
          .expected = 0,
      },
      {
          .tokens{200, 100},
          .power = 150,
          .expected = 1,
      },
      {
          .tokens{100, 200, 300, 400},
          .power = 200,
          .expected = 2,
      },
  };

  for (const auto &[tokens, power, expected] : test_cases) {
    const auto actual = Solution::bagOfTokensScore(tokens, power);
    REQUIRE(expected == actual);
  }
}
