#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int start;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 5, 3, std::nullopt, 4, 10, 6, 9, 2},
          .start = 3,
          .expected = 4,
      },
      {
          .root = {1},
          .start = 1,
          .expected = 0,
      },
  };

  for (const auto &[root, start, expected] : test_cases) {
    const auto actual = Solution::amountOfTime(root, start);
    REQUIRE(expected == actual);
  }
}
