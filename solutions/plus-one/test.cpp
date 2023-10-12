#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> digits;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .digits{1, 2, 3},
          .expected{1, 2, 4},
      },
      {
          .digits{4, 3, 2, 1},
          .expected{4, 3, 2, 2},
      },
      {
          .digits{9},
          .expected{1, 0},
      },
  };

  for (const auto &[digits, expected] : test_cases) {
    const auto actual = Solution::plusOne(digits);
    REQUIRE(expected == actual);
  }
}
