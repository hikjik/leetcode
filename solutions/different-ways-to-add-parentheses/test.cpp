#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string expression;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .expression = "2-1-1",
          .expected{0, 2},
      },
      {
          .expression = "2*3-4*5",
          .expected{-34, -14, -10, -10, 10},
      },
  };

  for (const auto &[expression, expected] : test_cases) {
    const auto actual = Solution::diffWaysToCompute(expression);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
