#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .expected = 4,
      },
      {
          .n = std::numeric_limits<int>::max(),
          .expected = 4,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::firstBadVersion(n);
    REQUIRE(expected == actual);
  }
}
