#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{0, 1}, {1, 0}},
          .expected{0, 1},
      },
      {
          .mat{{0, 0, 0}, {0, 1, 1}},
          .expected{1, 2},
      },
      {
          .mat{{0, 0}, {1, 1}, {0, 0}},
          .expected{1, 2},
      },
  };

  for (const auto &[mat, expected] : test_cases) {
    const auto actual = Solution::rowAndMaximumOnes(mat);
    REQUIRE(expected == actual);
  }
}
