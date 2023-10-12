#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{"@.a..", "###.#", "b.A.B"},
          .expected = 8,
      },
      {
          .grid{"@..aA", "..B#.", "....b"},
          .expected = 6,
      },
      {
          .grid{"@Aa"},
          .expected = -1,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::shortestPathAllKeys(grid);
    REQUIRE(expected == actual);
  }
}
