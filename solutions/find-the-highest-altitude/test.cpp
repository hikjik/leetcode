#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> gain;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .gain{-5, 1, 5, 0, -7},
          .expected = 1,
      },
      {
          .gain{-4, -3, -2, -1, 4, 3, 2},
          .expected = 0,
      },
  };

  for (const auto &[gain, expected] : test_cases) {
    const auto actual = Solution::largestAltitude(gain);
    REQUIRE(expected == actual);
  }
}
