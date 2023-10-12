#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, 2, 3, 4, 5, 6},
          .expected = true,
      },
      {
          .root{1, 2, 3, 4, 5, std::nullopt, 7},
          .expected = false,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::isCompleteTree(root);
    REQUIRE(expected == actual);
  }
}
