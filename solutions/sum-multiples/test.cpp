#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 7,
          .expected = 21,
      },
      {
          .n = 10,
          .expected = 40,
      },
      {
          .n = 9,
          .expected = 30,
      },
      {
          .n = 5,
          .expected = 8,
      },
      {
          .n = 3,
          .expected = 3,
      },
      {
          .n = 2,
          .expected = 0,
      },
      {
          .n = 1,
          .expected = 0,
      },
      {
          .n = 15,
          .expected = 81,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::sumOfMultiples(n);
    REQUIRE(expected == actual);
  }
}
