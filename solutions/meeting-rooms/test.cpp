#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .intervals{{0, 30}, {5, 10}, {15, 20}},
          .expected = false,
      },
      {
          .intervals{{7, 10}, {2, 4}},
          .expected = true,
      },
  };

  for (const auto &[intervals, expected] : test_cases) {
    const auto actual = Solution::canAttendMeetings(intervals);
    REQUIRE(expected == actual);
  }
}
