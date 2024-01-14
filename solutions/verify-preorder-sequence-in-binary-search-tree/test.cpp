#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> preorder;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .preorder{5, 2, 1, 3, 6},
          .expected = true,
      },
      {
          .preorder{5, 2, 6, 1, 3},
          .expected = false,
      },
      {
          .preorder{3, 1, 4, 2},
          .expected = false,
      },
  };

  for (const auto &[preorder, expected] : test_cases) {
    const auto actual = Solution::verifyPreorder(preorder);
    REQUIRE(expected == actual);
  }
}
