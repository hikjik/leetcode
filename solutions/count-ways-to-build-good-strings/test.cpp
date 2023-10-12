#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int low;
    int high;
    int zero;
    int one;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .low = 3,
          .high = 3,
          .zero = 1,
          .one = 1,
          .expected = 8,
      },
      {
          .low = 2,
          .high = 3,
          .zero = 1,
          .one = 2,
          .expected = 5,
      },
  };

  for (const auto &[low, high, zero, one, expected] : test_cases) {
    const auto actual = Solution::countGoodStrings(low, high, zero, one);
    REQUIRE(expected == actual);
  }
}
