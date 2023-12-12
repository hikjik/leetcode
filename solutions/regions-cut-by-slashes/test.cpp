#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{" /", "/ "},
          .expected = 2,
      },
      {
          .grid{" /", "  "},
          .expected = 1,
      },
      {
          .grid{"/\\", "\\/"},
          .expected = 5,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::regionsBySlashes(grid);
    REQUIRE(expected == actual);
  }
}
