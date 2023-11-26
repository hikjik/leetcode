#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{0, 0, 1}, {1, 1, 1}, {1, 0, 1}},
          .expected = 4,
      },
      {
          .matrix{{1, 0, 1, 0, 1}},
          .expected = 3,
      },
      {
          .matrix{{1, 1, 0}, {1, 0, 1}},
          .expected = 2,
      },
  };

  SECTION("Sorting") {
    for (const auto &[matrix, expected] : test_cases) {
      const auto actual = sorting::Solution::largestSubmatrix(matrix);
      REQUIRE(expected == actual);
    }
  }

  SECTION("No Sort") {
    for (const auto &[matrix, expected] : test_cases) {
      const auto actual = no_sort::Solution::largestSubmatrix(matrix);
      REQUIRE(expected == actual);
    }
  }
}
