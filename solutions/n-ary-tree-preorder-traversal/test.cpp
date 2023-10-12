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
          .root{1, std::nullopt, 3, 2, 4, std::nullopt, 5, 6},
          .expected{1, 3, 5, 6, 2, 4},
      },
      {
          .root{1,
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
          .expected{1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::preorder(root);
    REQUIRE(expected == actual);
  }
}
