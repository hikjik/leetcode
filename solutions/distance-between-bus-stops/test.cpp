#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> distance;
    int start;
    int destination;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .distance{1, 2, 3, 4},
          .start = 0,
          .destination = 1,
          .expected = 1,
      },
      {
          .distance{1, 2, 3, 4},
          .start = 0,
          .destination = 2,
          .expected = 3,
      },
      {
          .distance{1, 2, 3, 4},
          .start = 0,
          .destination = 3,
          .expected = 4,
      },
  };

  for (const auto &[distance, start, destination, expected] : test_cases) {
    const auto actual =
        Solution::distanceBetweenBusStops(distance, start, destination);
    REQUIRE(expected == actual);
  }
}
