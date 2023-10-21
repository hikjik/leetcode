#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int x;
    int y;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 2, 3, 4},
          .x = 4,
          .y = 3,
          .expected = false,
      },
      {
          .root = {1, 2, 3, std::nullopt, 4, std::nullopt, 5},
          .x = 5,
          .y = 4,
          .expected = true,
      },
      {
          .root = {1, 2, 3, std::nullopt, 4},
          .x = 2,
          .y = 3,
          .expected = false,
      },
  };

  for (const auto &[root, x, y, expected] : test_cases) {
    const auto actual = Solution::isCousins(root, x, y);
    REQUIRE(expected == actual);
  }
}
