#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    Tree subRoot;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{3, 4, 5, 1, 2},
          .subRoot{4, 1, 2},
          .expected = true,
      },
      {
          .root{3, 4, 5, 1, 2, std::nullopt, std::nullopt, std::nullopt,
                std::nullopt, 0},
          .subRoot{4, 1, 2},
          .expected = false,
      },
  };

  for (const auto &[root, subRoot, expected] : test_cases) {
    const auto actual = Solution::isSubtree(root, subRoot);
    REQUIRE(expected == actual);
  }
}
