#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> dislikes;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .dislikes{{1, 2}, {1, 3}, {2, 4}},
          .expected = true,
      },
      {
          .n = 3,
          .dislikes{{1, 2}, {1, 3}, {2, 3}},
          .expected = false,
      },
  };

  for (const auto &[n, dislikes, expected] : test_cases) {
    const auto actual = Solution::possibleBipartition(n, dislikes);
    REQUIRE(expected == actual);
  }
}
