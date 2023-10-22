#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, std::nullopt, 2, 2},
          .expected{2},
      },
      {
          .root = {0},
          .expected{0},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::findMode(root);
    REQUIRE(expected == actual);
  }
}
