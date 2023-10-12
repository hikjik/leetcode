#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .expected = true,
      },
      {
          .n = 16,
          .expected = true,
      },
      {
          .n = 3,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::isPowerOfTwo(n);
    REQUIRE(expected == actual);
  }
}
