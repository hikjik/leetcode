#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .expected = false,
      },
      {
          .n = 2,
          .expected = true,
      },
      {
          .n = 1000,
          .expected = true,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::divisorGame(n);
    REQUIRE(expected == actual);
  }
}
