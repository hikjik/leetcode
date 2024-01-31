#include <catch.hpp>

#include <solution.hpp>

#include <tree_node_with_parent.h>

#include <optional>
#include <vector>

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
          .q = 4,
          .expected = 5,
      },
      {
          .root{3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4},
          .p = 5,
          .q = 1,
          .expected = 3,
      },
      {
          .root{1, 2},
          .p = 1,
          .q = 2,
          .expected = 1,
      },
  };

  SECTION("Space Optimized") {
    for (const auto &[root, p, q, expected] : test_cases) {
      const auto lca =
          opt::Solution::lowestCommonAncestor(root.Find(p), root.Find(q));
      REQUIRE(lca != nullptr);
      REQUIRE(expected == lca->val);
    }
  }

  SECTION("HashSet") {
    for (const auto &[root, p, q, expected] : test_cases) {
      const auto lca =
          hash_set::Solution::lowestCommonAncestor(root.Find(p), root.Find(q));
      REQUIRE(lca != nullptr);
      REQUIRE(expected == lca->val);
    }
  }
}
