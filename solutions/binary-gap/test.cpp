#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 22,
          .expected = 2,
      },
      {
          .n = 8,
          .expected = 0,
      },
      {
          .n = 5,
          .expected = 2,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::binaryGap(n);
    REQUIRE(expected == actual);
  }
}
