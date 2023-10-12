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
          .root{1, 2, 2, 3, 4, 4, 3},
          .expected = true,
      },
      {
          .root{1, 2, 2, std::nullopt, 3, std::nullopt, 3},
          .expected = false,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::isSymmetric(root);
    REQUIRE(expected == actual);
  }
}
