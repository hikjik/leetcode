#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 1, 0, 0, 0},
               {1, 1, 1, 1, 0},
               {1, 0, 0, 0, 0},
               {1, 1, 0, 0, 0},
               {1, 1, 1, 1, 1}},
          .k = 3,
          .expected{2, 0, 3},
      },
      {
          .mat{{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}},
          .k = 2,
          .expected{0, 2},
      },
  };

  for (const auto &[mat, k, expected] : test_cases) {
    const auto actual = Solution::kWeakestRows(mat, k);
    REQUIRE(expected == actual);
  }
}
