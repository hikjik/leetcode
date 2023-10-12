#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int c;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .c = 5,
          .expected = true,
      },
      {
          .c = 3,
          .expected = false,
      },
  };

  for (const auto &[c, expected] : test_cases) {
    const auto actual = Solution::judgeSquareSum(c);
    REQUIRE(expected == actual);
  }
}
