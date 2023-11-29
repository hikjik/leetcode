#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> score;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .score{{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}},
          .k = 2,
          .expected{{7, 5, 11, 2}, {10, 6, 9, 1}, {4, 8, 3, 15}},
      },
      {
          .score{{3, 4}, {5, 6}},
          .k = 0,
          .expected{{5, 6}, {3, 4}},
      },
  };

  for (const auto &[score, k, expected] : test_cases) {
    const auto actual = Solution::sortTheStudents(score, k);
    REQUIRE(expected == actual);
  }
}
