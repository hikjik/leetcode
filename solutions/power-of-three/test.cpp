#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 27,
          .expected = true,
      },
      {
          .n = 0,
          .expected = false,
      },
      {
          .n = -1,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::isPowerOfThree(n);
    REQUIRE(expected == actual);
  }
}
