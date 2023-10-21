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
          .root = {1, 2, 3},
          .expected = 1,
      },
      {
          .root = {4, 2, 9, 3, 5, std::nullopt, 7},
          .expected = 15,
      },
      {
          .root = {21, 7, 14, 1, 1, 2, 2, 3, 3},
          .expected = 9,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::findTilt(root);
    REQUIRE(expected == actual);
  }
}
