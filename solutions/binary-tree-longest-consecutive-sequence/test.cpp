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
          .root = {1, std::nullopt, 3, 2, 4, std::nullopt, std::nullopt,
                   std::nullopt, 5},
          .expected = 3,
      },
      {
          .root = {2, std::nullopt, 3, 2, std::nullopt, 1},
          .expected = 2,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::longestConsecutive(root);
    REQUIRE(expected == actual);
  }
}
