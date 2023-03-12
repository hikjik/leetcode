#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(std::vector<std::optional<int>> values) {
  auto root = VectorToTree(values);

  Codec codec;
  auto root_decoded = codec.deserialize(codec.serialize(root));

  REQUIRE(EqualTree(root, root_decoded));

  FreeTree(root);
  FreeTree(root_decoded);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, 2, 3, std::nullopt, std::nullopt,
                                           4, 5};
    CheckSolution(values);
  }
  {
    std::vector<std::optional<int>> values;
    CheckSolution(values);
  }
}
