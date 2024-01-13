#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .intervals{{0, 30}, {5, 10}, {15, 20}},
          .expected = 2,
      },
      {
          .intervals{{7, 10}, {2, 4}},
          .expected = 1,
      },
  };

  for (const auto &[intervals, expected] : test_cases) {
    const auto actual = Solution::minMeetingRooms(intervals);
    REQUIRE(expected == actual);
  }
}
