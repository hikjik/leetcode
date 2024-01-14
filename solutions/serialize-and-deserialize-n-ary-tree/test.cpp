#include <catch.hpp>

#include <solution.hpp>

#include <node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
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
          .expected = {1,
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
      },
      {
          .root = {1, std::nullopt, 3, 2, 4, std::nullopt, 5, 6},
          .expected = {1, std::nullopt, 3, 2, 4, std::nullopt, 5, 6},
      },
      {
          .root = {},
          .expected = {},
      },
  };

  SECTION("LeetCode") {
    for (const auto &[root, expected] : test_cases) {
      const Tree actual = lc::Codec::deserialize(lc::Codec::serialize(root));
      REQUIRE(expected == actual);
    }
  }

  SECTION("DFS") {
    for (const auto &[root, expected] : test_cases) {
      const Tree actual = dfs::Codec::deserialize(dfs::Codec::serialize(root));
      REQUIRE(expected == actual);
    }
  }
}
