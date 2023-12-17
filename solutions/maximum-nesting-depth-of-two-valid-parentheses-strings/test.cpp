#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string seq;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .seq = "(()())",
          .expected{0, 1, 1, 1, 1, 0},
      },
      {
          .seq = "()(())()",
          .expected{0, 0, 0, 1, 1, 0, 0, 0},
      },
  };

  for (const auto &[seq, expected] : test_cases) {
    const auto actual = Solution::maxDepthAfterSplit(seq);
    REQUIRE(expected == actual);
  }
}
