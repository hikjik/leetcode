#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .expected = "((1,4),(2,3))",
      },
      {
          .n = 8,
          .expected = "(((1,8),(4,5)),((2,7),(3,6)))",
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::findContestMatch(n);
    REQUIRE(expected == actual);
  }
}
