#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{4, 2, 7, 1, 3, 6, 9},
          .expected{4, 7, 2, 9, 6, 3, 1},
      },
      {
          .root{2, 1, 3},
          .expected{2, 3, 1},
      },
      {
          .root{},
          .expected{},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const Tree actual = Solution::invertTree(Copy(root));
    REQUIRE(expected == actual);
  }
}
