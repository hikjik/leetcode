#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int lo;
    int hi;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .lo = 12,
          .hi = 15,
          .k = 2,
          .expected = 13,
      },
      {
          .lo = 7,
          .hi = 11,
          .k = 4,
          .expected = 7,
      },
      {
          .lo = 1,
          .hi = 1000,
          .k = 4,
          .expected = 8,
      },
  };

  for (const auto &[lo, hi, k, expected] : test_cases) {
    const auto actual = Solution::getKth(lo, hi, k);
    REQUIRE(expected == actual);
  }
}
