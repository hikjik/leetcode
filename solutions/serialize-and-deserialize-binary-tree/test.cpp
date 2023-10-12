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
          .root{1, 2, 3, std::nullopt, std::nullopt, 4, 5},
          .expected{1, 2, 3, std::nullopt, std::nullopt, 4, 5},
      },
      {
          .root{},
          .expected{},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    Codec codec;
    const Tree actual = codec.deserialize(codec.serialize(root));
    REQUIRE(expected == actual);
  }
}
