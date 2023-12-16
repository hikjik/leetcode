#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> customers;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .customers{{1, 2}, {2, 5}, {4, 3}},
          .expected = 5.00000,
      },
      {
          .customers{{5, 2}, {5, 4}, {10, 3}, {20, 1}},
          .expected = 3.25000,
      },
  };

  for (const auto &[customers, expected] : test_cases) {
    const auto actual = Solution::averageWaitingTime(customers);
    REQUIRE(expected == Approx(actual));
  }
}
