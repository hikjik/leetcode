#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {4, 1, 6, 0, 2, 5, 7, std::nullopt, std::nullopt,
                   std::nullopt, 3, std::nullopt, std::nullopt, std::nullopt,
                   8},
          .expected = {30, 36, 21, 36, 35, 26, 15, std::nullopt, std::nullopt,
                       std::nullopt, 33, std::nullopt, std::nullopt,
                       std::nullopt, 8},
      },
      {
          .root = {0, std::nullopt, 1},
          .expected = {1, std::nullopt, 1},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const Tree actual = Solution::convertBST(Copy(root));
    REQUIRE(expected == actual);
  }
}
