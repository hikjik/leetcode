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
          .n = 3,
          .expected = 2,
      },
      {
          .n = 1,
          .expected = 1,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::distinctIntegers(n);
    REQUIRE(expected == actual);
  }
}
