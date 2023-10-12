#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int rowIndex;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rowIndex = 3,
          .expected{1, 3, 3, 1},
      },
      {
          .rowIndex = 0,
          .expected{1},
      },
      {
          .rowIndex = 1,
          .expected{1, 1},
      },
  };

  for (const auto &[rowIndex, expected] : test_cases) {
    const auto actual = Solution::getRow(rowIndex);
    REQUIRE(expected == actual);
  }
}
