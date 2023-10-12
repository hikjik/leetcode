#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> days;
    std::vector<int> costs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .days{1, 4, 6, 7, 8, 20},
          .costs{2, 7, 15},
          .expected = 11,
      },
      {
          .days{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31},
          .costs{2, 7, 15},
          .expected = 17,
      },
  };

  for (const auto &[days, costs, expected] : test_cases) {
    const auto actual = Solution::mincostTickets(days, costs);
    REQUIRE(expected == actual);
  }
}
