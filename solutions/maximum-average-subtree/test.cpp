#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {5, 6, 1},
          .expected = 6.00000,
      },
      {
          .root = {0, std::nullopt, 1},
          .expected = 1.00000,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::maximumAverageSubtree(root);
    REQUIRE(expected == Approx(actual));
  }
}
