#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int maxDistance;
    std::vector<std::vector<int>> roads;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .maxDistance = 5,
          .roads{{0, 1, 2}, {1, 2, 10}, {0, 2, 10}},
          .expected = 5,
      },
      {
          .n = 3,
          .maxDistance = 5,
          .roads{{0, 1, 20}, {0, 1, 10}, {1, 2, 2}, {0, 2, 2}},
          .expected = 7,
      },
      {
          .n = 1,
          .maxDistance = 10,
          .roads{},
          .expected = 2,
      },
  };

  for (const auto &[n, maxDistance, roads, expected] : test_cases) {
    const auto actual = Solution::numberOfSets(n, maxDistance, roads);
    REQUIRE(expected == actual);
  }
}
