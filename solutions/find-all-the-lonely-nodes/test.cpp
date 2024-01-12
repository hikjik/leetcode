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
          .root = {1, 2, 3, std::nullopt, 4},
          .expected{4},
      },
      {
          .root = {7, 1, 4, 6, std::nullopt, 5, 3, std::nullopt, std::nullopt,
                   std::nullopt, std::nullopt, std::nullopt, 2},
          .expected{6, 2},
      },
      {
          .root = {11, 99, 88, 77, std::nullopt, std::nullopt, 66, 55,
                   std::nullopt, std::nullopt, 44, 33, std::nullopt,
                   std::nullopt, 22},
          .expected{77, 55, 33, 66, 44, 22},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::getLonelyNodes(root);
    REQUIRE(expected == actual);
  }
}
