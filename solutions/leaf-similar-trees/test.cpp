#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root1;
    Tree root2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root1{3, 5, 1, 6, 2, 9, 8, std::nullopt, std::nullopt, 7, 4},
          .root2{3, 5, 1, 6, 7, 4, 2, std::nullopt, std::nullopt, std::nullopt,
                 std::nullopt, std::nullopt, std::nullopt, 9, 8},
          .expected = true,
      },
      {
          .root1{1, 2, 3},
          .root2{1, 3, 2},
          .expected = false,
      },
  };

  for (const auto &[root1, root2, expected] : test_cases) {
    const auto actual = Solution::leafSimilar(root1, root2);
    REQUIRE(expected == actual);
  }
}
