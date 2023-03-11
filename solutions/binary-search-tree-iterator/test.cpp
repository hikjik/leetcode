#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

TEST_CASE("Simple") {
  std::vector<std::optional<int>> values{3, 1, 4, std::nullopt, 2};
  auto root = VectorToTree(values);

  auto iterator = new BSTIterator(root);
  for (auto a : {1, 2, 3, 4}) {
    REQUIRE(iterator->hasNext());
    REQUIRE(a == iterator->next());
  }
  REQUIRE_FALSE(iterator->hasNext());

  FreeTree(root);
}
