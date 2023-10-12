#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int numRows;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .numRows = 5,
          .expected{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}},
      },
      {
          .numRows = 1,
          .expected{{1}},
      },
  };

  for (const auto &[numRows, expected] : test_cases) {
    const auto actual = Solution::generate(numRows);
    REQUIRE(expected == actual);
  }
}
