#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {3, 9, 20, std::nullopt, std::nullopt, 15, 7},
          .expected{{9}, {3, 15}, {20}, {7}},
      },
      {
          .root = {3, 9, 8, 4, 0, 1, 7},
          .expected{{4}, {9}, {3, 0, 1}, {8}, {7}},
      },
      {
          .root = {3, 9, 8, 4, 0, 1, 7, std::nullopt, std::nullopt,
                   std::nullopt, 2, 5},
          .expected{{4}, {9, 5}, {3, 0, 1}, {8, 2}, {7}},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::verticalOrder(root);
    REQUIRE(expected == actual);
  }
}
