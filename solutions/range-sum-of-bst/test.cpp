#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int low;
    int high;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {10, 5, 15, 3, 7, std::nullopt, 18},
          .low = 7,
          .high = 15,
          .expected = 32,
      },
      {
          .root = {10, 5, 15, 3, 7, 13, 18, 1, std::nullopt, 6},
          .low = 6,
          .high = 10,
          .expected = 23,
      },
  };

  for (const auto &[root, low, high, expected] : test_cases) {
    const auto actual = Solution::rangeSumBST(root, low, high);
    REQUIRE(expected == actual);
  }
}
