#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{1, 2, 3}, {3, 1, 2}, {2, 3, 1}},
          .expected = true,
      },
      {
          .matrix{{1, 1, 1}, {1, 2, 3}, {1, 2, 3}},
          .expected = false,
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::checkValid(matrix);
    REQUIRE(expected == actual);
  }
}
