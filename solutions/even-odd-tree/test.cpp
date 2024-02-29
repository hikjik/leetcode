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
          .root = {1, 10, 4, 3, std::nullopt, 7, 9, 12, 8, 6, std::nullopt,
                   std::nullopt, 2},
          .expected = true,
      },
      {
          .root = {5, 4, 2, 3, 3, 7},
          .expected = false,
      },
      {
          .root = {5, 9, 1, 3, 5, 7},
          .expected = false,
      },
      {
          .root = {2, 12, 8, 5, 9, std::nullopt, std::nullopt, 18, 16},
          .expected = false,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::isEvenOddTree(root);
    REQUIRE(expected == actual);
  }
}
