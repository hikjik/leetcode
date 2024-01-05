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
          .root = {1, 2, 3, 4, 5, 6},
          .expected = 110,
      },
      {
          .root = {1, std::nullopt, 2, 3, 4, std::nullopt, std::nullopt, 5, 6},
          .expected = 90,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::maxProduct(root);
    REQUIRE(expected == actual);
  }
}
