#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> leftChild;
    std::vector<int> rightChild;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .leftChild{1, -1, 3, -1},
          .rightChild{2, -1, -1, -1},
          .expected = true,
      },
      {
          .n = 4,
          .leftChild{1, -1, 3, -1},
          .rightChild{2, 3, -1, -1},
          .expected = false,
      },
      {
          .n = 2,
          .leftChild{1, 0},
          .rightChild{-1, -1},
          .expected = false,
      },
      {
          .n = 4,
          .leftChild{1, 0, 3, -1},
          .rightChild{-1, -1, -1, -1},
          .expected = false,
      },
  };

  for (const auto &[n, leftChild, rightChild, expected] : test_cases) {
    const auto actual =
        Solution::validateBinaryTreeNodes(n, leftChild, rightChild);
    REQUIRE(expected == actual);
  }
}
