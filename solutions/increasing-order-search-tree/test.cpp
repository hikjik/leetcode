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
          .root = {5, 3, 6, 2, 4, std::nullopt, 8, 1, std::nullopt,
                   std::nullopt, std::nullopt, 7, 9},
          .expected = {1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4,
                       std::nullopt, 5, std::nullopt, 6, std::nullopt, 7,
                       std::nullopt, 8, std::nullopt, 9},
      },
      {
          .root = {5, 1, 7},
          .expected = {1, std::nullopt, 5, std::nullopt, 7},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const Tree actual = Solution::increasingBST(Copy(root));
    REQUIRE(expected == actual);
  }
}
