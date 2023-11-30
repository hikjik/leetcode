#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root1;
    Tree root2;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root1 = {2, 1, 4},
          .root2 = {1, 0, 3},
          .expected{0, 1, 1, 2, 3, 4},
      },
      {
          .root1 = {1, std::nullopt, 8},
          .root2 = {8, 1},
          .expected{1, 1, 8, 8},
      },
  };

  for (const auto &[root1, root2, expected] : test_cases) {
    const auto actual = Solution::getAllElements(root1, root2);
    REQUIRE(expected == actual);
  }
}
