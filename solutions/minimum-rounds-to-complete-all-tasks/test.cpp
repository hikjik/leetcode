#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> tasks;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .tasks{2, 2, 3, 3, 2, 4, 4, 4, 4, 4},
          .expected = 4,
      },
      {
          .tasks{2, 3, 3},
          .expected = -1,
      },
      {
          .tasks{5, 5, 5, 5},
          .expected = 2,
      },
  };

  for (const auto &[tasks, expected] : test_cases) {
    const auto actual = Solution::minimumRounds(tasks);
    REQUIRE(expected == actual);
  }
}
