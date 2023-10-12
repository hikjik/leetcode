#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int poured;
    int query_row;
    int query_glass;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .poured = 1,
          .query_row = 1,
          .query_glass = 1,
          .expected = 0.00000,
      },
      {
          .poured = 2,
          .query_row = 1,
          .query_glass = 1,
          .expected = 0.50000,
      },
      {
          .poured = 100000009,
          .query_row = 33,
          .query_glass = 17,
          .expected = 1.00000,
      },
  };

  for (const auto &[poured, query_row, query_glass, expected] : test_cases) {
    const auto actual =
        Solution::champagneTower(poured, query_row, query_glass);
    REQUIRE(expected == Approx(actual));
  }
}
