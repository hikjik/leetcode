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
          .root = {2, 3, 1, 3, 1, std::nullopt, 1},
          .expected = 2,
      },
      {
          .root = {2, 1, 1, 1, 3, std::nullopt, std::nullopt, std::nullopt,
                   std::nullopt, std::nullopt, 1},
          .expected = 1,
      },
      {
          .root = {9},
          .expected = 1,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::pseudoPalindromicPaths(root);
    REQUIRE(expected == actual);
  }
}
