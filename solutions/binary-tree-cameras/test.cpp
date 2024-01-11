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
          .root = {0, 0, std::nullopt, 0, 0},
          .expected = 1,
      },
      {
          .root = {0, 0, std::nullopt, 0, std::nullopt, 0, std::nullopt,
                   std::nullopt, 0},
          .expected = 2,
      },
      {
          .root = {0},
          .expected = 1,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::minCameraCover(root);
    REQUIRE(expected == actual);
  }
}
