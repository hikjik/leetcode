#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<std::vector<int>> grid{{0, 1}, {1, 0}};
  auto root = Solution::construct(grid);
  REQUIRE_FALSE(root->isLeaf);

  REQUIRE(root->topLeft->isLeaf);
  REQUIRE_FALSE(root->topLeft->val);

  REQUIRE(root->topRight->isLeaf);
  REQUIRE(root->topRight->val);

  REQUIRE(root->bottomLeft->isLeaf);
  REQUIRE(root->bottomLeft->val);

  REQUIRE(root->bottomRight->isLeaf);
  REQUIRE_FALSE(root->bottomRight->val);
}

TEST_CASE("Middle") {
  std::vector<std::vector<int>> grid{{{1, 1, 1, 1, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 1, 1, 1, 1},
                                      {1, 1, 1, 1, 1, 1, 1, 1},
                                      {1, 1, 1, 1, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 0, 0, 0, 0}}};
  auto root = Solution::construct(grid);
  REQUIRE_FALSE(root->isLeaf);

  REQUIRE(root->topLeft->isLeaf);
  REQUIRE(root->topLeft->val);

  REQUIRE(root->bottomLeft->isLeaf);
  REQUIRE(root->bottomLeft->val);

  REQUIRE(root->bottomRight->isLeaf);
  REQUIRE_FALSE(root->bottomRight->val);

  REQUIRE_FALSE(root->topRight->isLeaf);

  REQUIRE(root->topRight->topLeft->isLeaf);
  REQUIRE_FALSE(root->topRight->topLeft->val);

  REQUIRE(root->topRight->topRight->isLeaf);
  REQUIRE_FALSE(root->topRight->topRight->val);

  REQUIRE(root->topRight->bottomLeft->isLeaf);
  REQUIRE(root->topRight->bottomLeft->val);

  REQUIRE(root->topRight->bottomRight->isLeaf);
  REQUIRE(root->topRight->bottomRight->val);
}
