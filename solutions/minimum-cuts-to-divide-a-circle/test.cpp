#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .expected = 2,
      },
      {
          .n = 3,
          .expected = 3,
      },
      {
          .n = 1,
          .expected = 0,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::numberOfCuts(n);
    REQUIRE(expected == actual);
  }
}
