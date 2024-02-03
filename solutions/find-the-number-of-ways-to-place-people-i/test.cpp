#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .points{{1, 1}, {2, 2}, {3, 3}},
          .expected = 0,
      },
      {
          .points{{6, 2}, {4, 4}, {2, 6}},
          .expected = 2,
      },
      {
          .points{{3, 1}, {1, 3}, {1, 1}},
          .expected = 2,
      },
  };

  for (const auto &[points, expected] : test_cases) {
    const auto actual = Solution::numberOfPairs(points);
    REQUIRE(expected == actual);
  }
}
