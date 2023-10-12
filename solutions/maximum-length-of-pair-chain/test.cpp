#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> pairs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .pairs{{1, 2}, {2, 3}, {3, 4}},
          .expected = 2,
      },
      {
          .pairs{{1, 2}, {7, 8}, {4, 5}},
          .expected = 3,
      },
  };

  for (const auto &[pairs, expected] : test_cases) {
    const auto actual = Solution::findLongestChain(pairs);
    REQUIRE(expected == actual);
  }
}
