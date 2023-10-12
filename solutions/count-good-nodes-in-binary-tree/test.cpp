#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{3, 1, 4, 3, std::nullopt, 1, 5},
          .expected = 4,
      },
      {
          .root{3, 3, std::nullopt, 4, 2},
          .expected = 3,
      },
      {
          .root{1},
          .expected = 1,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::goodNodes(root);
    REQUIRE(expected == actual);
  }
}
