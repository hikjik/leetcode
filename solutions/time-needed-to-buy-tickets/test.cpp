#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> tickets;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .tickets{2, 3, 2},
          .k = 2,
          .expected = 6,
      },
      {
          .tickets{5, 1, 1, 1},
          .k = 0,
          .expected = 8,
      },
  };

  for (const auto &[tickets, k, expected] : test_cases) {
    const auto actual = Solution::timeRequiredToBuy(tickets, k);
    REQUIRE(expected == actual);
  }
}
