#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> students;
    std::vector<int> sandwiches;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .students{1, 1, 0, 0},
          .sandwiches{0, 1, 0, 1},
          .expected = 0,
      },
      {
          .students{1, 1, 1, 0, 0, 1},
          .sandwiches{1, 0, 0, 0, 1, 1},
          .expected = 3,
      },
  };

  for (const auto &[students, sandwiches, expected] : test_cases) {
    const auto actual = Solution::countStudents(students, sandwiches);
    REQUIRE(expected == actual);
  }
}
