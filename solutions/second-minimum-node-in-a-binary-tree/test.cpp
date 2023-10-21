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
          .root = {2, 2, 5, std::nullopt, std::nullopt, 5, 7},
          .expected = 5,
      },
      {
          .root = {2, 2, 2},
          .expected = -1,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::findSecondMinimumValue(root);
    REQUIRE(expected == actual);
  }
}
