#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string expression;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .expression = "T?2:3",
          .expected = "2",
      },
      {
          .expression = "F?1:T?4:5",
          .expected = "4",
      },
      {
          .expression = "T?T?F:5:3",
          .expected = "F",
      },
      {
          .expression = "F?1:T?2:3",
          .expected = "2",
      },
  };

  for (const auto &[expression, expected] : test_cases) {
    const auto actual = Solution::parseTernary(expression);
    REQUIRE(expected == actual);
  }
}
