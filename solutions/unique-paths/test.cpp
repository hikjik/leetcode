#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int m;
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .m = 3,
          .n = 7,
          .expected = 28,
      },
      {
          .m = 3,
          .n = 2,
          .expected = 3,
      },
  };

  for (const auto &[m, n, expected] : test_cases) {
    const auto actual = Solution::uniquePaths(m, n);
    REQUIRE(expected == actual);
  }
}
