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
          .root{3, 9, 20, std::nullopt, std::nullopt, 15, 7},
          .expected = 2,
      },
      {
          .root{2, std::nullopt, 3, std::nullopt, 4, std::nullopt, 5,
                std::nullopt, 6},
          .expected = 5,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::minDepth(root);
    REQUIRE(expected == actual);
  }
}
