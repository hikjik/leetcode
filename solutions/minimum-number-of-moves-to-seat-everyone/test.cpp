#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> seats;
    std::vector<int> students;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .seats{3, 1, 5},
          .students{2, 7, 4},
          .expected = 4,
      },
      {
          .seats{4, 1, 5, 9},
          .students{1, 3, 2, 6},
          .expected = 7,
      },
      {
          .seats{2, 2, 6, 6},
          .students{1, 3, 2, 6},
          .expected = 4,
      },
  };

  for (const auto &[seats, students, expected] : test_cases) {
    const auto actual = Solution::minMovesToSeat(seats, students);
    REQUIRE(expected == actual);
  }
}
