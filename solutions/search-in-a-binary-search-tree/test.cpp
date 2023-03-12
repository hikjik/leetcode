#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{4, 2, 7, 1, 3};
    auto root = VectorToTree(values);

    auto find = Solution::searchBST(root, 2);
    REQUIRE(find);
    REQUIRE(2 == find->val);

    REQUIRE_FALSE(Solution::searchBST(root, 5));

    FreeTree(root);
  }
}
