#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> startTime;
    std::vector<int> endTime;
    int queryTime;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .startTime{1, 2, 3},
          .endTime{3, 2, 7},
          .queryTime = 4,
          .expected = 1,
      },
      {
          .startTime{4},
          .endTime{4},
          .queryTime = 4,
          .expected = 1,
      },
  };

  for (const auto &[startTime, endTime, queryTime, expected] : test_cases) {
    const auto actual = Solution::busyStudent(startTime, endTime, queryTime);
    REQUIRE(expected == actual);
  }
}
