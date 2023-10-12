#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<char> tasks;
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .tasks{'A', 'A', 'A', 'B', 'B', 'B'},
          .n = 2,
          .expected = 8,
      },
      {
          .tasks{'A', 'A', 'A', 'B', 'B', 'B'},
          .n = 0,
          .expected = 6,
      },
      {
          .tasks{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'},
          .n = 2,
          .expected = 16,
      },
  };

  for (const auto &[tasks, n, expected] : test_cases) {
    const auto actual = Solution::leastInterval(tasks, n);
    REQUIRE(expected == actual);
  }
}
