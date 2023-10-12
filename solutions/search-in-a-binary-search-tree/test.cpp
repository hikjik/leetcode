#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int val;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{4, 2, 7, 1, 3},
          .val = 2,
          .expected{2, 1, 3},
      },
      {
          .root{4, 2, 7, 1, 3},
          .val = 5,
          .expected{},
      },
  };

  for (const auto &[root, val, expected] : test_cases) {
    const auto actual = Solution::searchBST(root, val);
    REQUIRE(expected == Tree(Copy(actual)));
  }
}
