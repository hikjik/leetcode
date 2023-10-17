#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int a;
    int b;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .a = 12,
          .b = 6,
          .expected = 4,
      },
      {
          .a = 25,
          .b = 30,
          .expected = 2,
      },
  };

  for (const auto &[a, b, expected] : test_cases) {
    const auto actual = Solution::commonFactors(a, b);
    REQUIRE(expected == actual);
  }
}
