#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 123,
          .expected = 321,
      },
      {
          .n = -123,
          .expected = -321,
      },
      {
          .n = 120,
          .expected = 21,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::reverse(n);
    REQUIRE(expected == actual);
  }
}
