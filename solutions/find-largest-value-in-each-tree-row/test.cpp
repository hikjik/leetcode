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
          .root{1, 3, 2, 5, 3, std::nullopt, 9},
          .expected{1, 3, 9},
      },
      {
          .root{1, 2, 3},
          .expected{1, 3},
      },
      {
          .root{},
          .expected{},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::largestValues(root);
    REQUIRE(expected == actual);
  }
}
