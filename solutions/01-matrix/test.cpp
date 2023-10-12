#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
          .expected{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
      },
      {
          .mat{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}},
          .expected{{0, 0, 0}, {0, 1, 0}, {1, 2, 1}},
      },
  };

  for (const auto &[mat, expected] : test_cases) {
    const auto actual = Solution::updateMatrix(mat);
    REQUIRE(expected == actual);
  }
}
