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
          .expected = 12,
      },
      {
          .n = 10,
          .expected = 83943898,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::stringCount(n);
    REQUIRE(expected == actual);
  }
}