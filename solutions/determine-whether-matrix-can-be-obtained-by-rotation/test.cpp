#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    std::vector<std::vector<int>> target;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{0, 1}, {1, 0}},
          .target{{1, 0}, {0, 1}},
          .expected = true,
      },
      {
          .mat{{0, 1}, {1, 1}},
          .target{{1, 0}, {0, 1}},
          .expected = false,
      },
      {
          .mat{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}},
          .target{{1, 1, 1}, {0, 1, 0}, {0, 0, 0}},
          .expected = true,
      },
  };

  for (const auto &[mat, target, expected] : test_cases) {
    const auto actual = Solution::findRotation(mat, target);
    REQUIRE(expected == actual);
  }
}
