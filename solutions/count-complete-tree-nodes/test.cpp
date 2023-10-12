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
          .root{1, 2, 3, 4, 5, 6},
          .expected = 6,
      },
      {
          .root{},
          .expected = 0,
      },
      {
          .root{1},
          .expected = 1,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::countNodes(root);
    REQUIRE(expected == actual);
  }
}
