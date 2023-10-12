#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int p;
    int q;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5},
          .p = 2,
          .q = 8,
          .expected = 6,
      },
      {
          .root{6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5},
          .p = 2,
          .q = 4,
          .expected = 2,
      },
      {
          .root{2, 1},
          .p = 2,
          .q = 1,
          .expected = 2,
      },
  };

  for (const auto &[root, p, q, expected] : test_cases) {
    const auto actual =
        Solution::lowestCommonAncestor(root, root.Find(p), root.Find(q));
    REQUIRE(actual);
    REQUIRE(expected == actual->val);
  }
}
