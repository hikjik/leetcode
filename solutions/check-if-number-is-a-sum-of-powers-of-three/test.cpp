#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 12,
          .expected = true,
      },
      {
          .n = 91,
          .expected = true,
      },
      {
          .n = 21,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::checkPowersOfThree(n);
    REQUIRE(expected == actual);
  }
}
