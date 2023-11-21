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
          .root = {3, 2, 3, std::nullopt, 3, std::nullopt, 1},
          .expected = 7,
      },
      {
          .root = {3, 4, 5, 1, 3, std::nullopt, 1},
          .expected = 9,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::rob(root);
    REQUIRE(expected == actual);
  }
}
