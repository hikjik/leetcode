#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> workers;
    std::vector<std::vector<int>> bikes;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .workers{{0, 0}, {2, 1}},
          .bikes{{1, 2}, {3, 3}},
          .expected{1, 0},
      },
      {
          .workers{{0, 0}, {1, 1}, {2, 0}},
          .bikes{{1, 0}, {2, 2}, {2, 1}},
          .expected{0, 2, 1},
      },
  };

  for (const auto &[workers, bikes, expected] : test_cases) {
    const auto actual = Solution::assignBikes(workers, bikes);
    REQUIRE(expected == actual);
  }
}
