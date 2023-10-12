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
          .root{3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4},
          .p = 5,
          .q = 1,
          .expected = 3,
      },
      {
          .root{3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4},
          .p = 5,
          .q = 4,
          .expected = 5,
      },
      {
          .root{1, 2},
          .p = 1,
          .q = 2,
          .expected = 1,
      },
  };

  for (const auto &[root, p, q, expected] : test_cases) {
    const auto actual =
        Solution::lowestCommonAncestor(root, root.Find(p), root.Find(q));
    REQUIRE(actual);
    REQUIRE(expected == actual->val);
  }
}
