#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 6,
          .expected = true,
      },
      {
          .n = 89,
          .expected = true,
      },
      {
          .n = 11,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::confusingNumber(n);
    REQUIRE(expected == actual);
  }
}
