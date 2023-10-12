#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::string traversal;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .traversal = "1-2--3--4-5--6--7",
          .expected{1, 2, 5, 3, 4, 6, 7},
      },
      {
          .traversal = "1-2--3---4-5--6---7",
          .expected{1, 2, 5, 3, std::nullopt, 6, std::nullopt, 4, std::nullopt,
                    7},
      },
      {
          .traversal = "1-401--349---90--88",
          .expected{1, 401, std::nullopt, 349, 88, 90},
      },
  };

  for (const auto &[traversal, expected] : test_cases) {
    const Tree actual = Solution::recoverFromPreorder(traversal);
    REQUIRE(expected == actual);
  }
}
