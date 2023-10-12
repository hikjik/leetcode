#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> satisfaction;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .satisfaction{-1, -8, 0, 5, -7},
          .expected = 14,
      },
      {
          .satisfaction{4, 3, 2},
          .expected = 20,
      },
      {
          .satisfaction{-1, -4, -5},
          .expected = 0,
      },
  };

  for (const auto &[satisfaction, expected] : test_cases) {
    const auto actual = Solution::maxSatisfaction(satisfaction);
    REQUIRE(expected == actual);
  }
}
