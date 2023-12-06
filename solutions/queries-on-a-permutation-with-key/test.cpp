#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> queries;
    int m;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .queries{3, 1, 2, 1},
          .m = 5,
          .expected{2, 1, 2, 1},
      },
      {
          .queries{4, 1, 2, 2},
          .m = 4,
          .expected{3, 1, 2, 0},
      },
      {
          .queries{7, 5, 5, 8, 3},
          .m = 8,
          .expected{6, 5, 0, 7, 5},
      },
  };

  SECTION("Naive") {
    for (const auto &[queries, m, expected] : test_cases) {
      const auto actual = naive::Solution::processQueries(queries, m);
      REQUIRE(expected == actual);
    }
  }

  SECTION("List") {
    for (const auto &[queries, m, expected] : test_cases) {
      const auto actual = list::Solution::processQueries(queries, m);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Ordered Set") {
    for (const auto &[queries, m, expected] : test_cases) {
      const auto actual = oset::Solution::processQueries(queries, m);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Segment Tree") {
    for (const auto &[queries, m, expected] : test_cases) {
      const auto actual = segment_tree::Solution::processQueries(queries, m);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Fenwick Tree") {
    for (const auto &[queries, m, expected] : test_cases) {
      const auto actual = bit::Solution::processQueries(queries, m);
      REQUIRE(expected == actual);
    }
  }
}
