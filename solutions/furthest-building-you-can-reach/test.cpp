#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> heights;
    int bricks;
    int ladders;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{4, 2, 7, 6, 9, 14, 12},
          .bricks = 5,
          .ladders = 1,
          .expected = 4,
      },
      {
          .heights{4, 12, 2, 7, 3, 18, 20, 3, 19},
          .bricks = 10,
          .ladders = 2,
          .expected = 7,
      },
      {
          .heights{14, 3, 19, 3},
          .bricks = 17,
          .ladders = 0,
          .expected = 3,
      },
  };

  for (const auto &[heights, bricks, ladders, expected] : test_cases) {
    const auto actual = Solution::furthestBuilding(heights, bricks, ladders);
    REQUIRE(expected == actual);
  }
}
