#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> flights;
    int src;
    int dst;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .flights{
              {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}},
          .src = 0,
          .dst = 3,
          .k = 1,
          .expected = 700,
      },
      {
          .n = 3,
          .flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}},
          .src = 0,
          .dst = 2,
          .k = 1,
          .expected = 200,
      },
      {
          .n = 3,
          .flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}},
          .src = 0,
          .dst = 2,
          .k = 0,
          .expected = 500,
      },
  };

  for (const auto &[n, flights, src, dst, k, expected] : test_cases) {
    const auto actual = Solution::findCheapestPrice(n, flights, src, dst, k);
    REQUIRE(expected == actual);
  }
}
