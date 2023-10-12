#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{3, 1, 4, std::nullopt, 2},
          .k = 1,
          .expected = 1,
      },
      {
          .root{5, 3, 6, 2, 4, std::nullopt, std::nullopt, 1},
          .k = 3,
          .expected = 3,
      },
  };

  for (const auto &[root, k, expected] : test_cases) {
    const auto actual = Solution::kthSmallest(root, k);
    REQUIRE(expected == actual);
  }
}
