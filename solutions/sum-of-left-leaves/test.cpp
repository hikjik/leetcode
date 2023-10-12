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
          .root{3, 9, 20, std::nullopt, std::nullopt, 15, 7},
          .expected = 24,
      },
      {
          .root{1},
          .expected = 0,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::sumOfLeftLeaves(root);
    REQUIRE(expected == actual);
  }
}
