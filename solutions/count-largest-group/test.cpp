#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 13,
          .expected = 4,
      },
      {
          .n = 2,
          .expected = 2,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countLargestGroup(n);
    REQUIRE(expected == actual);
  }
}
