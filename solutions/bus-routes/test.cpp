#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> routes;
    int source;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .routes{{1, 2, 7}, {3, 6, 7}},
          .source = 1,
          .target = 6,
          .expected = 2,
      },
      {
          .routes{{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}},
          .source = 15,
          .target = 12,
          .expected = -1,
      },
  };

  for (const auto &[routes, source, target, expected] : test_cases) {
    const auto actual = Solution::numBusesToDestination(routes, source, target);
    REQUIRE(expected == actual);
  }
}
