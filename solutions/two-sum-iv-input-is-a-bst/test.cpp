#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int k;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{5, 3, 6, 2, 4, std::nullopt, 7},
          .k = 9,
          .expected = true,
      },
      {
          .root{5, 3, 6, 2, 4, std::nullopt, 7},
          .k = 28,
          .expected = false,
      },
  };

  for (const auto &[root, k, expected] : test_cases) {
    const auto actual = Solution::findTarget(root, k);
    REQUIRE(expected == actual);
  }
}
