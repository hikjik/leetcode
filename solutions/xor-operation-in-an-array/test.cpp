#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int start;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .start = 0,
          .expected = 8,
      },
      {
          .n = 4,
          .start = 3,
          .expected = 8,
      },
  };

  for (const auto &[n, start, expected] : test_cases) {
    const auto actual = Solution::xorOperation(n, start);
    REQUIRE(expected == actual);
  }
}
