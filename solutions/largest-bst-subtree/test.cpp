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
          .root = {10, 5, 15, 1, 8, std::nullopt, 7},
          .expected = 3,
      },
      {
          .root = {4, 2, 7, 2, 3, 5, std::nullopt, 2, std::nullopt,
                   std::nullopt, std::nullopt, std::nullopt, std::nullopt, 1},
          .expected = 2,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::largestBSTSubtree(root);
    REQUIRE(expected == actual);
  }
}
