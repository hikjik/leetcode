#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> row;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .row{0, 3, 7, 1, 5, 2, 4, 6},
          .expected = 3,
      },
      {
          .row{0, 2, 1, 3},
          .expected = 1,
      },
      {
          .row{3, 2, 0, 1},
          .expected = 0,
      },
      {
          .row{},
          .expected = 0,
      },
  };

  for (const auto &[row, expected] : test_cases) {
    const auto actual = Solution::minSwapsCouples(row);
    REQUIRE(expected == actual);
  }
}
