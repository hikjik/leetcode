#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 19,
          .expected = true,
      },
      {
          .n = 2,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::isHappy(n);
    REQUIRE(expected == actual);
  }
}
