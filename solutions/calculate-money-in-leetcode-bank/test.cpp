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
          .expected = 10,
      },
      {
          .n = 10,
          .expected = 37,
      },
      {
          .n = 20,
          .expected = 96,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::totalMoney(n);
    REQUIRE(expected == actual);
  }
}
