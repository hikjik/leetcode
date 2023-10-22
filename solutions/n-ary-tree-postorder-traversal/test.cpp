#include <catch.hpp>

#include <solution.hpp>

#include <node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, std::nullopt, 3, 2, 4, std::nullopt, 5, 6},
          .expected{5, 6, 3, 2, 4, 1},
      },
      {
          .root = {1,
                   std::nullopt,
                   2,
                   3,
                   4,
                   5,
                   std::nullopt,
                   std::nullopt,
                   6,
                   7,
                   std::nullopt,
                   8,
                   std::nullopt,
                   9,
                   10,
                   std::nullopt,
                   std::nullopt,
                   11,
                   std::nullopt,
                   12,
                   std::nullopt,
                   13,
                   std::nullopt,
                   std::nullopt,
                   14},
          .expected{2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::postorder(root);
    REQUIRE(expected == actual);
  }
}
