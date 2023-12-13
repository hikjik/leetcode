#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> preorder;
    std::vector<int> postorder;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .preorder{1, 2, 4, 5, 3, 6, 7},
          .postorder{4, 5, 2, 6, 7, 3, 1},
          .expected = {1, 2, 3, 4, 5, 6, 7},
      },
      {
          .preorder{1},
          .postorder{1},
          .expected = {1},
      },
  };

  for (const auto &[preorder, postorder, expected] : test_cases) {
    const Tree actual = Solution::constructFromPrePost(preorder, postorder);
    REQUIRE(expected == actual);
  }
}
