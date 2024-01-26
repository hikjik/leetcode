#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> seats;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .seats{1, 0, 0, 0, 1, 0, 1},
          .expected = 2,
      },
      {
          .seats{1, 0, 0, 0},
          .expected = 3,
      },
      {
          .seats{0, 1},
          .expected = 1,
      },
  };

  for (const auto &[seats, expected] : test_cases) {
    const auto actual = Solution::maxDistToClosest(seats);
    REQUIRE(expected == actual);
  }
}
