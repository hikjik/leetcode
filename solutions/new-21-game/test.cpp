#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    int maxPts;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 10,
          .k = 1,
          .maxPts = 10,
          .expected = 1.00000,
      },
      {
          .n = 6,
          .k = 1,
          .maxPts = 10,
          .expected = 0.60000,
      },
      {
          .n = 21,
          .k = 17,
          .maxPts = 10,
          .expected = 0.73278,
      },
  };

  for (const auto &[n, k, maxPts, expected] : test_cases) {
    const auto actual = Solution::new21Game(n, k, maxPts);
    REQUIRE(expected == Approx(actual));
  }
}
