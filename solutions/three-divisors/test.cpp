#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected = false,
      },
      {
          .n = 4,
          .expected = true,
      },
      {
          .n = 81,
          .expected = false,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::isThree(n);
    REQUIRE(expected == actual);
  }
}
