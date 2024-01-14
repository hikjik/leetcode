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
          .expected = 2,
      },
      {
          .root = {2, 1, 3},
          .expected = 3,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::longestConsecutive(root);
    REQUIRE(expected == actual);
  }
}
