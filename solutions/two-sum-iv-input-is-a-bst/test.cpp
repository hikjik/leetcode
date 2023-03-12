#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{5, 3, 6, 2, 4, std::nullopt, 7};
    auto root = VectorToTree(values);

    REQUIRE(Solution::findTarget(root, 9));
    REQUIRE_FALSE(Solution::findTarget(root, 28));

    FreeTree(root);
  }
}
