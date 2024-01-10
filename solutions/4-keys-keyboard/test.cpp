#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .expected = 3,
      },
      {
          .n = 7,
          .expected = 9,
      },
      {
          .n = 10,
          .expected = 20,
      },
      {
          .n = 11,
          .expected = 27,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::maxA(n);
    REQUIRE(expected == actual);
  }
}
