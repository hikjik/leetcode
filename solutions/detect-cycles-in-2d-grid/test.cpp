#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> grid;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{'a', 'a', 'a', 'a'},
                {'a', 'b', 'b', 'a'},
                {'a', 'b', 'b', 'a'},
                {'a', 'a', 'a', 'a'}},
          .expected = true,
      },
      {
          .grid{{'c', 'c', 'c', 'a'},
                {'c', 'd', 'c', 'c'},
                {'c', 'c', 'e', 'c'},
                {'f', 'c', 'c', 'c'}},
          .expected = true,
      },
      {
          .grid{{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}},
          .expected = false,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::containsCycle(grid);
    REQUIRE(expected == actual);
  }
}
