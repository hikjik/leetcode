#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> processorTime;
    std::vector<int> tasks;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .processorTime{8, 10},
          .tasks{2, 2, 3, 1, 8, 7, 4, 5},
          .expected = 16,
      },
      {
          .processorTime{10, 20},
          .tasks{2, 3, 1, 2, 5, 8, 4, 3},
          .expected = 23,
      },
  };

  for (const auto &[processorTime, tasks, expected] : test_cases) {
    const auto actual = Solution::minProcessingTime(processorTime, tasks);
    REQUIRE(expected == actual);
  }
}
