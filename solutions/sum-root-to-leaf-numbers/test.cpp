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
          .root{1, 2, 3},
          .expected = 25,
      },
      {
          .root{4, 9, 0, 5, 1},
          .expected = 1026,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::sumNumbers(root);
    REQUIRE(expected == actual);
  }
}
