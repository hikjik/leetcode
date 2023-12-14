#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int low;
    int high;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 0, 2},
          .low = 1,
          .high = 2,
          .expected = {1, std::nullopt, 2},
      },
      {
          .root = {3, 0, 4, std::nullopt, 2, std::nullopt, std::nullopt, 1},
          .low = 1,
          .high = 3,
          .expected = {3, 2, std::nullopt, 1},
      },
  };

  for (const auto &[root, low, high, expected] : test_cases) {
    const Tree actual = Solution::trimBST(Copy(root), low, high);
    REQUIRE(expected == actual);
  }
}
